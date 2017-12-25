<?php

/**
 * Implement hook_form()
 * Form add order
 */
function fee_add_form($form, &$form_state, $entity)
{
  global $user;

  $form['fee'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#weight' => 0
  );

  $form['fee']['fee_total'] = array(
    '#title' => t('Total cost'),
    '#type' => 'textfield',
    '#require' => true,
  );
  $form['fee']['fee_date'] = array(
    '#type' => 'date_popup',
    '#title' => t('Day'),
    '#default_value' => 'now',
    '#require' => FALSE,
    '#date_format' => 'Y-m-d',
    '#date_label_position' => 'within',
    '#date_increment' => 15,
    '#date_year_range' => '-3:+10',
  );
  $form['fee']['reason'] = array(
    '#type' => 'textarea',
    '#title' => t('Reason'),
    '#require' => true,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save costs')
  );
  return $form;
}

/**
 * Implement hook_form_validate()
 * validate price for fee
 */

function fee_add_form_validate($form, &$form_state)
{
  if (empty($form_state['values']['fee_total'])) {
    form_set_error('fee_total', t('Please enter a cost.'));
  }

  if (empty($form_state['values']['fee_date'])) {
    form_set_error('fee_date', t('Please select a date.'));
  }
  if (empty($form_state['values']['reason'])) {
    form_set_error('reason', t('Please enter a valid reason.'));
  }

}

/**
 * Implement hook_form_submit()
 * Save fee
 */

function fee_add_form_submit($form, &$form_state)
{
    global $user;
    $entity = new stdClass();
    $entity->uid = $user->uid;
    $entity->fee_total = $form_state['values']['fee_total'];
    $entity->fee_date = strtotime($form_state['values']['fee_date']);
    $entity->reason = $form_state['values']['reason'];
    $entity->created = REQUEST_TIME;
    $entity->changed = REQUEST_TIME;
    if (fee_create($entity)) {
      drupal_set_message(t('The charge has been successfully created.'), 'status');
      $form_state['redirect'] = 'app/fee/manager';
    } else {
      drupal_set_message(t('Charge was not created successfully. Please try again.'), 'error');
    }
}

/**
 * Implement hook_form()
 * Form delete fee
 */
function fee_delete_form($form, &$form_state, $entity)
{
  $form_state['fee'] = $entity;
  $form['title'] = array(
    '#markup' => t('<h3>Do you want to delete @title ?</h3>', array('@title' => $entity->reason)),
  );
  $form['cancel'] = array(
    '#markup' => '<div class="cancel-link">' . l('Cancel', 'app/fee/manager', array('attributes' => array('id' => 'edit-cancel'))) . '</div>'
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Delete')
  );
  return $form;

}

/**
 * Implement hook_form_submit
 * Delete drink
 */
function fee_delete_form_submit($form, &$form_state)
{
  $entity = $form_state['fee'];
  fee_delete($entity->id);
  drupal_set_message(t('@title has been successfully deleted.', array('@title' => $entity->reason)), 'status');
  $form_state['redirect'] = 'app/fee/manager';
}

/**
 * Implement manage thu chi
 */
function fee_manager_form($form, &$form_state){
  $from = null;
  $to = null;
  $label_fun = t('Turnover today');
  $label_fee = t('Cost today');
  $form['#method'] = 'get';
  $form['from'] = array(
    '#type' => 'date_popup',
    '#title' => t('Since'),
    '#default_value' => 'now',
    '#require' => FALSE,
    '#date_format' => 'Y-m-d',
    '#date_label_position' => 'within',
    '#date_increment' => 15,
    '#date_year_range' => '-3:+10',
  );
  $form['to'] = array(
    '#type' => 'date_popup',
    '#title' => t('To date'),
    '#default_value' => 'now',
    '#require' => FALSE,
    '#date_format' => 'Y-m-d',
    '#date_label_position' => 'within',
    '#date_increment' => 15,
    '#date_year_range' => '-3:+10',
  );

  $form['submit'] = array(
    '#type'=>'submit',
    '#value'=>t('Xem')
  );
  if(isset($_GET['from']['date']) &&!empty($_GET['from']['date']) && isset($_GET['to']['date']) && !empty($_GET['to']['date'])){
    $to = strtotime($_GET['to']['date']);
    $from = strtotime($_GET['from']['date']);
    $label_fun = t('Turnover from day '.date('d/m/Y',$from).' to date '.date('d/m/Y',$to));
    $label_fee = t('Cost from date '.date('d/m/Y',$from).' to date '.date('d/m/Y',$to));
  }
  elseif(isset($_GET['from']['date']) && !empty($_GET['from']['date']) && !$_GET['to']['date']){
    $from = strtotime($_GET['from']['date']);
    $label_fun = t('Turnover from day '.date('d/m/Y',$from));
    $label_fee = t('Cost from date '.date('d/m/Y',$from));
  }
  elseif(isset($_GET['to']['date']) && !empty($_GET['to']['date']) && !$_GET['from']['date']){
    $to = strtotime($_GET['to']['date']);
    $label_fun = t('Turnover from day '.date('d/m/Y',$to));
    $label_fee = t('Cost from date '.date('d/m/Y',$to));
  }
  $fun = fee_get_total_fun($from, $to);
  $fun_result = theme('fee_fun',array('fun'=>$fun));
  $fee = fee_get_fee_fun($from, $to);
  $fee_result = theme('fee_fee',array('fee'=>$fee));



  $form['get_total'] = array(
    '#markup'=>'<div class="total-get-fun"><h3>'.$label_fun.'</h3>'.$fun_result.'</div>',
  );
  $form['get_fee'] = array(
    '#markup'=>'<div class="total-get-fee"><h3>'.$label_fee.'</h3>'.$fee_result.'</div>',
  );
  $form['from_value'] = array(
    '#type'=>'hidden',
    '#value' => isset($_GET['from']['date']) ? $_GET['from']['date'] : '',
    '#attributes'=>array('class'=>'fromdate_value')
  );
  $form['to_value'] = array(
    '#type'=>'hidden',
    '#value' => isset($_GET['to']['date']) ? $_GET['to']['date'] : '',
    '#attributes'=>array('class'=>'todate_value')
  );
  return $form;
}
