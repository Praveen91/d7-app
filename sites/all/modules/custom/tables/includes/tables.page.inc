<?php

/**
 * Implement hook_form()
 * Form add table
 */
function tables_add_form($form, &$form_state, $entity) {
  //dsm($entity);
  if (isset($entity)) {
    $form_state['tables'] = $entity;
  }
  global $user;
  $form['tables'] = array(
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#weight' => 0
    );
  $form['tables']['uid'] = array(
      '#type' => 'hidden',
      '#value' => isset($entity->uid) ? $entity->uid : $user->uid
    );
  $form['tables']['name'] = array(
    '#title' => t('Table name'),
    '#type' => 'textfield',
    '#default_value' => isset($entity->name) ? $entity->name : '',
    '#require' => true,
    '#attributes' => array('placeholder' => t('Ex. Table 1'))
  );
  $form['tables']['price'] = array(
    '#type' => 'textfield',
    '#title' => t('Price / hour (INR)'),
    '#default_value' => isset($entity->price) ? $entity->price : '',
    '#require' => true,
    '#attributes' => array('placeholder' => t('Ex. 450'))
  );

  $form['tables']['created'] = array(
    '#type' => 'hidden',
    '#value' => isset($entity->created_at) ? $entity->created_at : REQUEST_TIME,
  );
  $form['tables']['changed'] = array(
    '#type' => 'hidden',
    '#value' => REQUEST_TIME,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Keep the table')
  );
  return $form;
}

/**
 * Implement hook_form_validate()
 * validate price for tables
 */
function tables_add_form_validate($form, &$form_state) {
  if (empty($form_state['values']['name'])) {
    form_set_error('name', t('Please enter a name for the table.'));
  }
  if (tables_get_tables('name', $form_state['values']['name']) && empty($form_state['tables'])) {
    form_set_error('name', t('Table '. $form_state['values']['name'] .'
already exists in the system. You should consider when adding.'));
  }
  if (empty($form_state['values']['price'])) {
    form_set_error('price', t('Please enter a price for the table.'));
  }
  if (!is_numeric($form_state['values']['price'])) {
    form_set_error('price', t('Charges may not contain letters or special characters.'));
  }
}

/**
 * Implement hook_form_submit()
 * Saves tables
 */
function tables_add_form_submit($form, &$form_state) {

  //check is_new or update
  if (isset($form_state['tables']) && !empty($form_state['tables'])) {
     $entity = $form_state['tables'];
     $entity->name = $form_state['values']['name'];
     $entity->price = $form_state['values']['price'];
     $entity->changed = $form_state['values']['changed'];
     if (tables_save($entity)) {
        drupal_set_message(t('Table ' . $form_state['values']['name'] . ' has been updated successfully.'), 'status');
        $form_state['redirect'] = 'app/tables/manager';
     } else {
        drupal_set_message(t('Table ' . $form_state['values']['name'] . 'Not updated successfully. Please try again.'), 'error');
     }
   }
   else {
  $entity = new stdClass();
  $entity->uid = $form_state['values']['uid'];
  $entity->name = $form_state['values']['name'];
  $entity->price = $form_state['values']['price'];
  $entity->created = $form_state['values']['created'];
  $entity->changed = $form_state['values']['changed'];
   if (tables_create($entity)) {
      drupal_set_message(t('Tables ' . $form_state['values']['name'] . ' was created successfully.'), 'status');
      $form_state['redirect'] = 'app/tables/manager';
      } else {
      drupal_set_message(t('Tables ' . $form_state['values']['name'] . ' was not created successfully. Please try again.'), 'error');
      }
   }
}

/**
 * Implement hook_form()
 * Form delete tables
 */
function tables_delete_form($form, &$form_state, $entity)
{
  $form_state['tables'] = $entity;
  $form['title'] = array(
    '#markup' => t('<h3>Do you want to delete @title ?</h3>', array('@title' => $entity->name)),
  );
  $form['cancel'] = array(
    '#markup' => '<div class="cancel-link">' . l('Cancel', 'app/tables/manager', array('attributes' => array('id' => 'edit-cancel'))) . '</div>'
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
function tables_delete_form_submit($form, &$form_state)
{
  $entity = $form_state['tables'];
  tables_delete($entity->id);
  drupal_set_message(t('@title was successfully deleted.', array('@title' => $entity->name)), 'status');
  $form_state['redirect'] = 'app/tables/manager';
}
