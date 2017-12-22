<?php

/**
 * Implement hook_form.
 */
function cook_table_add_form($form, &$form_state, $entity) {
  global $user;
  if (isset($entity)) {
    $form_state['cook_table'] = $entity;
  }
  $form['cook_table'] = [
   '#type' => 'fieldset',
   '#collapsible' => TRUE,
   '#collapsed' => FALSE,
   '#weight' => 0,
  ];
  $form['cook_table']['uid'] = [
    '#type' => 'hidden',
    '#value' => isset($entity->uid) ? $entity->uid : $user->uid
  ];
  $form['cook_table']['cook_name'] = [
    '#type' => 'textfield',
    '#title' => t('Name of drink'),
    '#default_value' => isset($entity->name) ? $entity->name : '',
    '#required' => TRUE,
  ];
  $form['cook_table']['price'] = [
    '#type' => 'textfield',
    '#title' => t('Price (INR)'),
    '#default_value' => isset($entity->price) ? $entity->price : '',
    '#required' => TRUE,
  ];
  $status = FALSE;
  if (in_array('seller', $user->roles)) {
    $status = TRUE;
  }
  $form['cook_table']['stock'] = [
   '#type' => 'textfield',
   '#title' => t('Inventory'),
   '#default_value' => isset($entity->stock) ? $entity->stock : '',
   '#require' => TRUE,
   '#attributes'=>array('disabled'=>$status),
  ];
  $form['cook_table']['created'] = [
    '#type' => 'hidden',
    '#value' => isset($entity->created) ? $entity->created : REQUEST_TIME,
  ];
  $form['cook_table']['changed'] = [
    '#type' => 'hidden',
    '#value' => REQUEST_TIME,
  ];

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save menu')
  );

  return $form;
}

/**
 * Implement hook_form_validate.
 */
function cook_table_add_form_validate($form, &$form_state) {
if (empty($form_state['values']['cook_name'])) {
  form_set_error('cook_name', t('Please enter a menu name.'));
}
if (cook_table_get_cook_table('name', $form_state['values']['cook_name']) && empty($form_state['cook_table'])) {
  form_set_error('cook_name', t('The menu already exists in the system. You should consider when adding.'));
}
if (empty($form_state['values']['price'])) {
  form_set_error('price', t('Please enter a price for the menu.'));
}
if (!is_numeric($form_state['values']['price'])) {
  form_set_error('price', t('Charges may not contain letters or special characters.'));
}
}

/**
 * Implement hook_form_submit()
 * Save cook_table
 */
function cook_table_add_form_submit($form, &$form_state) {
 //check is_new or update
if (isset($form_state['cook_table']) && !empty($form_state['cook_table'])) {
    $entity = $form_state['cook_table'];
    $entity->name = $form_state['values']['cook_name'];
    $entity->price = $form_state['values']['price'];
    $entity->stock = !empty($form_state['values']['stock']) ? $form_state['values']['price'] : 0;
    $entity->changed = $form_state['values']['changed'];
    if (cook_table_save($entity)) {
      drupal_set_message(t('Menu' .$form_state['values']['cook_name']. ' has been updated successfully.'), 'status');
       $form_state['redirect'] = 'app/cook-table/manager';
    } else {
      drupal_set_message(t('Menu' .$form_state['values']['cook_name']. ' Not updated successfully. Please try again.') , 'error');
    }

} else {
 $entity = new stdClass();
 $entity->uid = $form_state['values']['uid'];
 $entity->name = $form_state['values']['cook_name'];
 $entity->price = $form_state['values']['price'];
 $entity->stock = !empty($form_state['values']['stock']) ? $form_state['values']['stock'] : 0;
 $entity->created = date('Y-m-d H:i:s',$form_state['values']['created']);
 $entity->changed = date('Y-m-d H:i:s',$form_state['values']['changed']);
if (cook_table_create($entity)) {
  drupal_set_message(t('Menu' . $form_state['values']['cook_name'] . ' was created successfully.'), 'status');
   $form_state['redirect'] = 'app/cook-table/manager';
} else {
  drupal_set_message(t('Menu' . $form_state['values']['cook_name'] . ' was not created successfully. Please try again.'));
 }
}
}

/**
 * Implements hook_form()
 * Form delete cook_table.
 */
function cook_table_delete_form($form, &$form_state, $entity) {
  $form_state['cook_table'] = $entity;
  $form['title'] = [
    '#markup' => t('<h3> Do you want to delete @title?</h3>', array('@title' => $entity->name)),
  ];
  $form['cancel'] = [
   '#markup' => t('<div class = "cancel-link">' . l('Cancel', 'app/cook-table/manager', array('attributes' => array('id' => 'edit-cancel'))) .'</div>'),
  ];
  $form['submit'] = [
   '#type' => 'submit',
   '#value' => t('Delete'),
  ];
return $form;
}

/**
 * Implement hook_form_submit
 * Delete drink
 */
function cook_table_delete_form_submit($form, &$form_state) {
  $entity = $form_state['cook_table'];
  cook_table_delete($entity->id);
  drupal_set_message(t('@title was deleted successfully
', array('@title' => $entity->name)), 'status');
  $form_state['redirect'] = 'app/cook-table/manager';
}
