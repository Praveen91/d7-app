<?php

/**
 * Implement hook_form
 * Add form setting for customer
 */
function app_setting_form($form, &$form_state){
   $form['name'] = array(
     '#type'=>'textfield',
     '#default_value'=> variable_get('name','Name of Billiards Club'),
   );
  $form['site_address'] = array(
    '#type' => 'textfield',
    '#default_value'=> variable_get('site_address','Activity address'),
  );
  $form['site_email'] = array(
    '#type' => 'textfield',
    '#default_value'=> variable_get('site_email','Club Email'),
  );
  $form['site_phone'] = array(
    '#type' => 'textfield',
    '#default_value'=> variable_get('site_phone','Club Phone'),
  );
   return system_settings_form($form);
}
