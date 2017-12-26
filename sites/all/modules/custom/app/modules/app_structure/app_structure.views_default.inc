<?php
/**
 * @file
 * app_structure.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function app_structure_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'fee_manager';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'fee';
  $view->human_name = 'Fee manager';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Fee manager';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'fee:*:add';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<ul class="action-links"><li><a href="/fee/add">Thêm Chi phí</a></li></ul>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'fee';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['fee_total']['id'] = 'fee_total';
  $handler->display->display_options['fields']['fee_total']['table'] = 'fee';
  $handler->display->display_options['fields']['fee_total']['field'] = 'fee_total';
  $handler->display->display_options['fields']['fee_total']['label'] = 'Cost';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['fee_date']['id'] = 'fee_date';
  $handler->display->display_options['fields']['fee_date']['table'] = 'fee';
  $handler->display->display_options['fields']['fee_date']['field'] = 'fee_date';
  $handler->display->display_options['fields']['fee_date']['label'] = 'Date spent';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['reason']['id'] = 'reason';
  $handler->display->display_options['fields']['reason']['table'] = 'fee';
  $handler->display->display_options['fields']['reason']['field'] = 'reason';
  $handler->display->display_options['fields']['reason']['label'] = 'Reason for spending';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['id_1']['id'] = 'id_1';
  $handler->display->display_options['fields']['id_1']['table'] = 'fee';
  $handler->display->display_options['fields']['id_1']['field'] = 'id';
  $handler->display->display_options['fields']['id_1']['label'] = 'Action';
  $handler->display->display_options['fields']['id_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['id_1']['alter']['text'] = '<a id="edit-cancel" href="/fee/delete/[id]">Xóa</a>';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'app/fee/manager';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Cost management';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['fee_manager'] = $view;

  $view = new view();
  $view->name = 'stock_in';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'stock_in';
  $view->human_name = 'Stock in';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Manage storage';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'stock:*:manage';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Stock In: Stock in ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'stock_in';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Stock In: Cook_table */
  $handler->display->display_options['fields']['cook_table']['id'] = 'cook_table';
  $handler->display->display_options['fields']['cook_table']['table'] = 'stock_in';
  $handler->display->display_options['fields']['cook_table']['field'] = 'cook_table';
  $handler->display->display_options['fields']['cook_table']['label'] = '';
  $handler->display->display_options['fields']['cook_table']['exclude'] = TRUE;
  $handler->display->display_options['fields']['cook_table']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['cook_table']['separator'] = '';
  /* Field: Stock In: Qty */
  $handler->display->display_options['fields']['qty']['id'] = 'qty';
  $handler->display->display_options['fields']['qty']['table'] = 'stock_in';
  $handler->display->display_options['fields']['qty']['field'] = 'qty';
  $handler->display->display_options['fields']['qty']['label'] = 'Quantity';
  $handler->display->display_options['fields']['qty']['precision'] = '0';
  /* Field: Stock In: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'stock_in';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date of entry';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd/m/Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Sort criterion: Stock In: Created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'stock_in';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Stock In: Cook_table */
  $handler->display->display_options['filters']['cook_table']['id'] = 'cook_table';
  $handler->display->display_options['filters']['cook_table']['table'] = 'stock_in';
  $handler->display->display_options['filters']['cook_table']['field'] = 'cook_table';
  $handler->display->display_options['filters']['cook_table']['exposed'] = TRUE;
  $handler->display->display_options['filters']['cook_table']['expose']['operator_id'] = 'cook_table_op';
  $handler->display->display_options['filters']['cook_table']['expose']['label'] = 'Products';
  $handler->display->display_options['filters']['cook_table']['expose']['operator'] = 'cook_table_op';
  $handler->display->display_options['filters']['cook_table']['expose']['identifier'] = 'cook_table';
  $handler->display->display_options['filters']['cook_table']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'app/stock-in';
  $export['stock_in'] = $view;

  $view = new view();
  $view->name = 'stock_out';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'stock_out';
  $view->human_name = 'Stock out';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Managing repositories';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'stock:*:manage';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Stock Out: Stock out ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'stock_out';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = 'ID';
  /* Field: Stock Out: Cook_table */
  $handler->display->display_options['fields']['cook_table']['id'] = 'cook_table';
  $handler->display->display_options['fields']['cook_table']['table'] = 'stock_out';
  $handler->display->display_options['fields']['cook_table']['field'] = 'cook_table';
  $handler->display->display_options['fields']['cook_table']['label'] = '';
  $handler->display->display_options['fields']['cook_table']['exclude'] = TRUE;
  $handler->display->display_options['fields']['cook_table']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['cook_table']['separator'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Products';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Stock Out: Order_id */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'stock_out';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['label'] = 'Invoice number';
  $handler->display->display_options['fields']['order_id']['separator'] = '';
  /* Field: Stock Out: Qty */
  $handler->display->display_options['fields']['qty']['id'] = 'qty';
  $handler->display->display_options['fields']['qty']['table'] = 'stock_out';
  $handler->display->display_options['fields']['qty']['field'] = 'qty';
  $handler->display->display_options['fields']['qty']['label'] = 'Quantity';
  $handler->display->display_options['fields']['qty']['precision'] = '0';
  /* Field: Stock Out: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'stock_out';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Delivery date';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd/m/Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Sort criterion: Stock Out: Created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'stock_out';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Stock Out: Cook_table */
  $handler->display->display_options['filters']['cook_table']['id'] = 'cook_table';
  $handler->display->display_options['filters']['cook_table']['table'] = 'stock_out';
  $handler->display->display_options['filters']['cook_table']['field'] = 'cook_table';
  $handler->display->display_options['filters']['cook_table']['exposed'] = TRUE;
  $handler->display->display_options['filters']['cook_table']['expose']['operator_id'] = 'cook_table_op';
  $handler->display->display_options['filters']['cook_table']['expose']['label'] = 'Products';
  $handler->display->display_options['filters']['cook_table']['expose']['operator'] = 'cook_table_op';
  $handler->display->display_options['filters']['cook_table']['expose']['identifier'] = 'cook_table';
  $handler->display->display_options['filters']['cook_table']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Stock Out: Order_id */
  $handler->display->display_options['filters']['order_id']['id'] = 'order_id';
  $handler->display->display_options['filters']['order_id']['table'] = 'stock_out';
  $handler->display->display_options['filters']['order_id']['field'] = 'order_id';
  $handler->display->display_options['filters']['order_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['order_id']['expose']['operator_id'] = 'order_id_op';
  $handler->display->display_options['filters']['order_id']['expose']['label'] = 'Number of invoices';
  $handler->display->display_options['filters']['order_id']['expose']['operator'] = 'order_id_op';
  $handler->display->display_options['filters']['order_id']['expose']['identifier'] = 'order_id';
  $handler->display->display_options['filters']['order_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Date: Date (stock_out) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'stock_out';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'app/stock-out';
  $export['stock_out'] = $view;

  $view = new view();
  $view->name = 'user_management';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'User Management';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Manage users';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<ul class="action-links"><li><a href="/admin/people/create?destination=account/manager">Add account</a></li></ul>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'users';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: User: Roles */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  /* Field: User: Active */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'users';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  $handler->display->display_options['fields']['status']['type'] = 'active-blocked';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Operations';
  $handler->display->display_options['fields']['edit_node']['element_type'] = '0';
  $handler->display->display_options['fields']['edit_node']['element_class'] = 'action-links';
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['operator'] = 'not';
  $handler->display->display_options['filters']['rid']['value'] = array(
    3 => '3',
  );
  /* Filter criterion: User: The user ID */
  $handler->display->display_options['filters']['uid_raw']['id'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['table'] = 'users';
  $handler->display->display_options['filters']['uid_raw']['field'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['operator'] = '>';
  $handler->display->display_options['filters']['uid_raw']['value']['value'] = '0';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'account/manager';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Manage users';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['user_management'] = $view;

  return $export;
}
