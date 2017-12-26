<?php
/**
 * @file
 * app_structure.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function app_structure_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_cost-management:app/fee/manager.
  $menu_links['main-menu_cost-management:app/fee/manager'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'app/fee/manager',
    'router_path' => 'app/fee/manager',
    'link_title' => 'Cost management',
    'options' => array(
      'identifier' => 'main-menu_cost-management:app/fee/manager',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: main-menu_desk-manager:app/tables/manager.
  $menu_links['main-menu_desk-manager:app/tables/manager'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'app/tables/manager',
    'router_path' => 'app/tables/manager',
    'link_title' => 'Desk manager',
    'options' => array(
      'identifier' => 'main-menu_desk-manager:app/tables/manager',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: main-menu_home:<front>.
  $menu_links['main-menu_home:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'identifier' => 'main-menu_home:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: main-menu_manage-users:account/manager.
  $menu_links['main-menu_manage-users:account/manager'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'account/manager',
    'router_path' => 'account/manager',
    'link_title' => 'Manage users',
    'options' => array(
      'identifier' => 'main-menu_manage-users:account/manager',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: main-menu_warehouse-management-and-menu:app/cook-table/manager.
  $menu_links['main-menu_warehouse-management-and-menu:app/cook-table/manager'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'app/cook-table/manager',
    'router_path' => 'app/cook-table/manager',
    'link_title' => 'Warehouse Management and Menu',
    'options' => array(
      'identifier' => 'main-menu_warehouse-management-and-menu:app/cook-table/manager',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Cost management');
  t('Desk manager');
  t('Home');
  t('Manage users');
  t('Warehouse Management and Menu');

  return $menu_links;
}
