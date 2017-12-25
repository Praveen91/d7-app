<?php

/**
 * Implement hook_form.
 * Add stock form.
 */
function stock_add_form($form, &$form_state, $entity) {
  global $user;
  if (isset($entity)) {
    $form_state['stock'] = $entity;
  }
  $form['cook_table'] = [
   '#type' => 'select',
   '#title' => t('Menu item'),
   '#options' => app_get_cook_table_array(),
  ];
  $form['qty'] = [
   '#type' => 'textfield',
   '#title' => t('Quantity'),
   '#default_value' => 1,
  ];
  $form['submit'] = [
   '#type' => 'submit',
   '#value' => t('Save Stock')
  ];
}

/**
 * Implement hook_form_validate.
 * Validate Quantity and stock add form.
 */
function stock_add_form_validate($form, &$form_state) {
  if (empty($form_state['values']['cook_table'])) {
    form_set_error('cook_table', t('Please select menu item.'));
  }
  if (empty($form_state['values']['qty']) && $form_state['values']['qty'] > 1 ) {
    form_set_error('qty', t('Quantity must be larger than 1 unit'));
  }
}

/**
 * Implement hook_form_submit.
 * Save stock form
 */
function stock_add_form_submit($form, &$form_state) {
  $cook = cook_table_load($form_state['values']['cook_table']);
  $qty = $form_state['values']['qty'];
  app_stock_in($qty, $cook);
  drupal_set_message(t('Warehouse for '.$cook->name.' success.'));
  $form_state['redirect'] = 'app/cook-table/manager';
}
