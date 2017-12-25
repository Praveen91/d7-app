<?php

/**
 * Implement hook_form.
 */
function order_debt_form($form, &$form_state, $order) {
  $form_state['order'] = $order;
  $form['id'] = [
   '#type' => 'textfield',
   '#title' => t('Some bills'),
   '#default_value' => $order->id,
   '#attributes' => array('disable' =>TRUE),
  ];
  $form['date_order'] = [
   '#type' => 'textfield',
   '#title' => t(''),
   '#default_value' => format_date($order->created, 'custom', 'd/m/Y'),
   '#attributes' => array('disable' => TRUE),
  ];
   $form['customer'] = array(
    '#type'=>'textfield',
    '#title' => 'Customer',
    '#default_value' => $order->customer,
    '#attributes'=>array('disabled'=>true),
  );
  $form['total'] = array(
    '#type'=>'textfield',
    '#title' => 'Total payment',
    '#default_value' => number_format($order->total_all_amount ).' INR',
    '#attributes'=>array('disabled'=>true),
  );
  $form['debt'] = array(
    '#type'=>'textfield',
    '#title' => 'Debts',
    '#default_value' => number_format($order->exist_amount).' INR',
    '#attributes'=>array('disabled'=>true),
  );
  $form['paid'] = array(
    '#type'=>'textfield',
    '#title' => 'Prepay',
    '#default_value' => number_format($order->paid).' INR',
    '#attributes'=>array('disabled'=>true),
  );
  $form['paid_today'] = array(
    '#type'=>'textfield',
    '#title' => 'Pay',
  );
  $form['submit'] = array(
    '#type'=>'submit',
    '#value'=>'Pay'
  );
  return $form;
}

/**
 * Implement hook_form_validate.
 */
function order_debt_form_validate($form, &$form_state) {
  if (empty($form_state['values']['paid_today'])) {
    form_set_error('paid_today', t('Please enter the payment amount.
'));
  }
}

/**
 * Implement hook_form_submit.
 */
function order_debt_form_submit($form, &$form_state) {
  $order = $form_state['order'];
  $total = $order->total_all_amount - ($form_state['values']['paid_today'] + $order->paid);
  if($total == 0){
    $order->exist_amount = 0;
    $order->paid = $order->total_all_amount;
    $order->debt = 0;
  }else{
    $order->exist_amount = $total;
    $order->paid = $order->total_all_amount - $total;
  }
  order_save($order);
  drupal_set_message(t('Payment success.'));
  $form_state['redirect'] = 'app/order/debt';
}
