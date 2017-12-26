<?php
/**
 * @file
 * app_structure.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function app_structure_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  // Exported role: seller.
  $roles['seller'] = array(
    'name' => 'seller',
    'weight' => 3,
  );

  return $roles;
}
