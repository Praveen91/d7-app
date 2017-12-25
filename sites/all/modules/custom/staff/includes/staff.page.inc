<?php

/**
 * Implement hook_form().
 * Staff form.
 */
function staff_add_form($form, &$form_state, $entity) {
  global $user;
  if (isset($entity)) {
    $form_state['staff'] = $entity;
  }

  $form['staff'] = [
   '#type' => 'fieldset',
   '#collapsible' => TRUE,
   '#collapsed' => FALSE,
   '#weight' => 0,
  ];
  $form['staff']['uid'] = [
   '#type' => 'hidden',
   '#value' => isset($entity->uid) ? $entity->uid : $user->uid,
  ];
  $form['staff']['name'] = [
   '#type' => 'textfield',
   '#title' => t("Staff's name"),
   '#default_value' => isset($entity->name) ? $entity->name : '',
   '#require' => true,
   '#attributes' => array('placeholder' => t('Mr Praveen')),
  ];
  $form['staff']['phone'] = [
   '#type' => 'textfield',
   '#title' => t('Phone'),
   '#default_value' => isset($entity->phone) ? $entity->phone : '',
   '#required' => true,
   '#attributes' => array('placeholder' => t('Ex. 8181878044')),
  ];
  $form['staff']['card_id'] = [
   '#type' => 'textfield',
   '#title' => t('ID card No'),
   '#default_value' => isset($entity->card_id) ? $entity->card_id : '',
   '#required' => true,
   '#attributes' => array('placeholder' => t('Ex. 81814')),
  ];
  $form['staff']['address'] = [
   '#type' => 'textfield',
   '#title' => t('Address'),
   '#default_value' => isset($entity->address) ? $entity->address : '',
   '#required' => true,
   '#attributes' => array('placeholder' => t('Ex. Office No 8...')),
  ];
  $form['staff']['birthday'] = [
   '#type' => 'date_popup',
   '#title' => t('Birthday'),
   '#default_value' => isset($entity->birthday) ? $entity->birthday : '',
   '#required' => FALSE,
   '#attributes' => array('placeholder' => t('Ex. 1990-08-01')),
   '#date_format' => 'd/m/Y',
   '#date_label_position' => 'within',
   '#date_increment' => 15,
   '#date_year_range' => '-90:+0',
  ];
  $form['staff']['startdate'] = array(
    '#type' => 'date_popup',
    '#title' => t('Date start work'),
    '#default_value' => isset($entity->startdate) ? $entity->startdate : '',
    '#require' => true,
    '#attributes' => array('placeholder' => t('Ex. 1990-06-01')),
    '#date_format' => 'd/m/Y',
    '#date_label_position' => 'within',
    '#date_increment' => 15,
    '#date_year_range' => '-90:+0',
  );
  $form['staff']['created'] = [
   '#type' => 'hidden',
   '#value' => isset($entity->created) ? $entity->created : REQUEST_TIME,
  ];
   $form['staff']['changed'] = [
   '#type' => 'hidden',
   '#value' => REQUEST_TIME,
  ];
  $form['staff']['submit'] = [
   '#type' => 'submit',
   '#value' => t('Save Employees'),
  ];
  return $form;
}

/**
 * Implement hook_form_validate.
 * Validate data for staff
 */
function staff_add_form_validate($form, &$form_state) {
  if (empty($form_state['values']['name'])) {
    form_set_error('name', t('Please enter Staff Name.'));
  }
  if (staff_get_staff('name', $form_state['values']['name']) && empty($form_state['staff'])) {
    form_set_error('name', t('Mr' . $form_state['values']['name'] . 'already exists in the system. You should consider when adding.'));
  }
  if (empty($form_state['values']['card_id'])) {
    form_set_error('card_id', t('Please enter ID'));
  }
  if (empty($form_state['values']['phone'])) {
   form_set_error('phone', t('Please enter a phone number.'));
  }
  if (!is_numeric($form_state['values']['card_id'])) {
    form_set_error('card_id', t('ID cards may not contain letters or special characters.'));
  }
  if (!is_numeric($form_state['values']['phone'])) {
    form_set_error('phone', t('Phone must not contain letters or special characters.'));
  }
}

/**
 * Implements hook_form_submit().
 * Save Staff.
 */
function staff_add_form_submit($form, &$form_state) {
 //check is_new or update
  // dsm($form_state);
  if (isset($form_state['staff']) && !empty($form_state['staff'])) {
    $entity = $form_state['staff'];
    $entity->uid = $form_state['values']['uid'];
    $entity->name = $form_state['values']['name'];
    $entity->phone = $form_state['values']['phone'];
    $entity->card_id = $form_state['values']['card_id'];
    $entity->address = $form_state['values']['address'];
    $entity->birthday = $form_state['values']['birthday'];
    $entity->startdate = $form_state['values']['startdate'];
    $entity->changed = $form_state['values']['changed'];
    if (staff_save($entity)) {
      drupal_set_message(t('Staff ' . $form_state['values']['name'] . ' has been updated successfully.'), 'status');
      $form_state['redirect'] = 'app/staff/manager';
    } else {
      drupal_set_message(t('Staff ' . $form_state['values']['name'] . ' Not updated successfully. Please try again.'), 'error');
    }
  } else {
  $entity = new stdClass();
  $entity->uid = $form_state['values']['uid'];
  $entity->name = $form_state['values']['name'];
  $entity->phone = $form_state['values']['phone'];
  $entity->card_id = $form_state['values']['card_id'];
  $entity->address = $form_state['values']['address'];
  $entity->birthday = $form_state['values']['birthday'];
  $entity->startdate = $form_state['values']['startdate'];
  $entity->created = $form_state['values']['created'];
  $entity->changed = $form_state['values']['changed'];
  if (staff_create($entity)) {
    drupal_set_message(t('Staff' . $form_state['values']['name'] . 'was created successfully.'), 'status');
    $form_state['redirect'] = 'app/staff/manager';
  } else {
    drupal_set_message(t('Staff' .$form_state['values']['name']. ' was not created successfully. Please try again.'), 'error');
   }
  }
}

/**
 * Implement hook_form().
 * Staff delete form.
 */
function staff_delete_form($form, &$form_state, $entity) {
  $form_state['staff'] = $entity;
  $form['title'] = [
   '#markup' => t('<h3>Do you want to delete @title?</h3>', array('@title' => $entity->name)),
  ];
  $form['cancel'] = [
   '#markup' => '<div class="cancel-link">' . l('Cancel', 'app/staff/manager' , array('attributes' => array('id' => 'edit-cancel'))) . '</div>',
  ];
  $form['submit'] = [
   '#type' => 'submit',
   '#value' => t('Delete'),
  ];
  return $form;
}

/**
 * Implement staff_delete_form_submit().
 * Action Staff Delete.
 */
function staff_delete_form_submit($form, &$form_state) {
  $entity = $form_state['staff'];
  staff_delete($entity->id);
  drupal_set_message(t('@title was successfully deleted.', array('@title' => $entity->name )), 'status');
  $form_state['redirect'] = 'app/staff/manager';
}
