<?php
/**
 * @file
 * app_order_structure.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function app_order_structure_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'debt_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'orders';
  $view->human_name = 'Debt list';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Debt control';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Order: Order ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'orders';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Order: Customer */
  $handler->display->display_options['fields']['customer']['id'] = 'customer';
  $handler->display->display_options['fields']['customer']['table'] = 'orders';
  $handler->display->display_options['fields']['customer']['field'] = 'customer';
  /* Field: Order: Changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'orders';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Day';
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'd/m/Y H:i:s';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Order: Exist_amount */
  $handler->display->display_options['fields']['exist_amount']['id'] = 'exist_amount';
  $handler->display->display_options['fields']['exist_amount']['table'] = 'orders';
  $handler->display->display_options['fields']['exist_amount']['field'] = 'exist_amount';
  $handler->display->display_options['fields']['exist_amount']['label'] = 'In debt';
  $handler->display->display_options['fields']['exist_amount']['precision'] = '0';
  /* Field: Order: Paid */
  $handler->display->display_options['fields']['paid']['id'] = 'paid';
  $handler->display->display_options['fields']['paid']['table'] = 'orders';
  $handler->display->display_options['fields']['paid']['field'] = 'paid';
  $handler->display->display_options['fields']['paid']['label'] = 'Prepay';
  $handler->display->display_options['fields']['paid']['precision'] = '0';
  /* Field: Order: Promotion */
  $handler->display->display_options['fields']['promotion']['id'] = 'promotion';
  $handler->display->display_options['fields']['promotion']['table'] = 'orders';
  $handler->display->display_options['fields']['promotion']['field'] = 'promotion';
  $handler->display->display_options['fields']['promotion']['label'] = 'Sale';
  $handler->display->display_options['fields']['promotion']['precision'] = '0';
  /* Field: Order: Table_id */
  $handler->display->display_options['fields']['table_id']['id'] = 'table_id';
  $handler->display->display_options['fields']['table_id']['table'] = 'orders';
  $handler->display->display_options['fields']['table_id']['field'] = 'table_id';
  $handler->display->display_options['fields']['table_id']['label'] = 'Table';
  /* Field: Order: Total_all_amount */
  $handler->display->display_options['fields']['total_all_amount']['id'] = 'total_all_amount';
  $handler->display->display_options['fields']['total_all_amount']['table'] = 'orders';
  $handler->display->display_options['fields']['total_all_amount']['field'] = 'total_all_amount';
  $handler->display->display_options['fields']['total_all_amount']['label'] = 'Total payment';
  $handler->display->display_options['fields']['total_all_amount']['precision'] = '0';
  /* Field: Order: Total_amount */
  $handler->display->display_options['fields']['total_amount']['id'] = 'total_amount';
  $handler->display->display_options['fields']['total_amount']['table'] = 'orders';
  $handler->display->display_options['fields']['total_amount']['field'] = 'total_amount';
  $handler->display->display_options['fields']['total_amount']['label'] = 'Total';
  $handler->display->display_options['fields']['total_amount']['precision'] = '0';
  /* Field: Order: Order ID */
  $handler->display->display_options['fields']['id_1']['id'] = 'id_1';
  $handler->display->display_options['fields']['id_1']['table'] = 'orders';
  $handler->display->display_options['fields']['id_1']['field'] = 'id';
  $handler->display->display_options['fields']['id_1']['label'] = 'See the bill';
  $handler->display->display_options['fields']['id_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['id_1']['alter']['text'] = '<a class="action" target="_blank" href="/app/print/[id]">Xem hóa đơn</a>
<a id="edit-cancel"  href="/app/order/debt/[id]">Thanh toán</a>';
  $handler->display->display_options['fields']['id_1']['separator'] = '';
  /* Sort criterion: Order: Order ID */
  $handler->display->display_options['sorts']['id']['id'] = 'id';
  $handler->display->display_options['sorts']['id']['table'] = 'orders';
  $handler->display->display_options['sorts']['id']['field'] = 'id';
  $handler->display->display_options['sorts']['id']['order'] = 'DESC';
  /* Filter criterion: Order: Debt */
  $handler->display->display_options['filters']['debt']['id'] = 'debt';
  $handler->display->display_options['filters']['debt']['table'] = 'orders';
  $handler->display->display_options['filters']['debt']['field'] = 'debt';
  $handler->display->display_options['filters']['debt']['value']['value'] = '1';
  /* Filter criterion: Order: Customer */
  $handler->display->display_options['filters']['customer']['id'] = 'customer';
  $handler->display->display_options['filters']['customer']['table'] = 'orders';
  $handler->display->display_options['filters']['customer']['field'] = 'customer';
  $handler->display->display_options['filters']['customer']['operator'] = 'contains';
  $handler->display->display_options['filters']['customer']['exposed'] = TRUE;
  $handler->display->display_options['filters']['customer']['expose']['operator_id'] = 'customer_op';
  $handler->display->display_options['filters']['customer']['expose']['label'] = 'Customer';
  $handler->display->display_options['filters']['customer']['expose']['operator'] = 'customer_op';
  $handler->display->display_options['filters']['customer']['expose']['identifier'] = 'customer';
  $handler->display->display_options['filters']['customer']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'app/order/debt';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Debt control';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['path'] = 'app/order/debt/export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'app/order/debt';
  $handler->display->display_options['segment_size'] = '100';
  $export['debt_list'] = $view;

  $view = new view();
  $view->name = 'order_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'orders';
  $view->human_name = 'Order List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Invoice Management';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Order: Order ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'orders';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Order: Customer */
  $handler->display->display_options['fields']['customer']['id'] = 'customer';
  $handler->display->display_options['fields']['customer']['table'] = 'orders';
  $handler->display->display_options['fields']['customer']['field'] = 'customer';
  /* Field: Order: Changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'orders';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Day';
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'd/m/Y H:i:s';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Order: Exist_amount */
  $handler->display->display_options['fields']['exist_amount']['id'] = 'exist_amount';
  $handler->display->display_options['fields']['exist_amount']['table'] = 'orders';
  $handler->display->display_options['fields']['exist_amount']['field'] = 'exist_amount';
  $handler->display->display_options['fields']['exist_amount']['label'] = 'In debt';
  $handler->display->display_options['fields']['exist_amount']['precision'] = '0';
  /* Field: Order: Paid */
  $handler->display->display_options['fields']['paid']['id'] = 'paid';
  $handler->display->display_options['fields']['paid']['table'] = 'orders';
  $handler->display->display_options['fields']['paid']['field'] = 'paid';
  $handler->display->display_options['fields']['paid']['label'] = 'Prepay';
  $handler->display->display_options['fields']['paid']['precision'] = '0';
  /* Field: Order: Promotion */
  $handler->display->display_options['fields']['promotion']['id'] = 'promotion';
  $handler->display->display_options['fields']['promotion']['table'] = 'orders';
  $handler->display->display_options['fields']['promotion']['field'] = 'promotion';
  $handler->display->display_options['fields']['promotion']['label'] = 'Sale';
  $handler->display->display_options['fields']['promotion']['precision'] = '0';
  /* Field: Order: Table_id */
  $handler->display->display_options['fields']['table_id']['id'] = 'table_id';
  $handler->display->display_options['fields']['table_id']['table'] = 'orders';
  $handler->display->display_options['fields']['table_id']['field'] = 'table_id';
  $handler->display->display_options['fields']['table_id']['label'] = 'Table';
  /* Field: Order: Total_all_amount */
  $handler->display->display_options['fields']['total_all_amount']['id'] = 'total_all_amount';
  $handler->display->display_options['fields']['total_all_amount']['table'] = 'orders';
  $handler->display->display_options['fields']['total_all_amount']['field'] = 'total_all_amount';
  $handler->display->display_options['fields']['total_all_amount']['label'] = 'Total payment';
  $handler->display->display_options['fields']['total_all_amount']['precision'] = '0';
  /* Field: Order: Note */
  $handler->display->display_options['fields']['note']['id'] = 'note';
  $handler->display->display_options['fields']['note']['table'] = 'orders';
  $handler->display->display_options['fields']['note']['field'] = 'note';
  /* Field: Order: Total_amount */
  $handler->display->display_options['fields']['total_amount']['id'] = 'total_amount';
  $handler->display->display_options['fields']['total_amount']['table'] = 'orders';
  $handler->display->display_options['fields']['total_amount']['field'] = 'total_amount';
  $handler->display->display_options['fields']['total_amount']['label'] = 'Total';
  $handler->display->display_options['fields']['total_amount']['precision'] = '0';
  /* Field: Order: Order ID */
  $handler->display->display_options['fields']['id_1']['id'] = 'id_1';
  $handler->display->display_options['fields']['id_1']['table'] = 'orders';
  $handler->display->display_options['fields']['id_1']['field'] = 'id';
  $handler->display->display_options['fields']['id_1']['label'] = 'See the bill';
  $handler->display->display_options['fields']['id_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['id_1']['alter']['text'] = '<a class="action" target="_blank" href="/app/print/[id]">See the bill</a>';
  $handler->display->display_options['fields']['id_1']['separator'] = '';
  /* Sort criterion: Order: Order ID */
  $handler->display->display_options['sorts']['id']['id'] = 'id';
  $handler->display->display_options['sorts']['id']['table'] = 'orders';
  $handler->display->display_options['sorts']['id']['field'] = 'id';
  $handler->display->display_options['sorts']['id']['order'] = 'DESC';
  /* Filter criterion: Order: Customer */
  $handler->display->display_options['filters']['customer']['id'] = 'customer';
  $handler->display->display_options['filters']['customer']['table'] = 'orders';
  $handler->display->display_options['filters']['customer']['field'] = 'customer';
  $handler->display->display_options['filters']['customer']['operator'] = 'contains';
  $handler->display->display_options['filters']['customer']['exposed'] = TRUE;
  $handler->display->display_options['filters']['customer']['expose']['operator_id'] = 'customer_op';
  $handler->display->display_options['filters']['customer']['expose']['label'] = 'Customer';
  $handler->display->display_options['filters']['customer']['expose']['operator'] = 'customer_op';
  $handler->display->display_options['filters']['customer']['expose']['identifier'] = 'customer';
  $handler->display->display_options['filters']['customer']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'app/order';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Invoice Management';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'app/order/export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'app/order';
  $handler->display->display_options['segment_size'] = '100';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Invoice Management';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Order: Order ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'orders';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Order: Customer */
  $handler->display->display_options['fields']['customer']['id'] = 'customer';
  $handler->display->display_options['fields']['customer']['table'] = 'orders';
  $handler->display->display_options['fields']['customer']['field'] = 'customer';
  /* Field: Order: Table_id */
  $handler->display->display_options['fields']['table_id']['id'] = 'table_id';
  $handler->display->display_options['fields']['table_id']['table'] = 'orders';
  $handler->display->display_options['fields']['table_id']['field'] = 'table_id';
  $handler->display->display_options['fields']['table_id']['label'] = 'Table';
  /* Field: Order: Total_amount */
  $handler->display->display_options['fields']['total_amount']['id'] = 'total_amount';
  $handler->display->display_options['fields']['total_amount']['table'] = 'orders';
  $handler->display->display_options['fields']['total_amount']['field'] = 'total_amount';
  $handler->display->display_options['fields']['total_amount']['label'] = 'Total';
  $handler->display->display_options['fields']['total_amount']['precision'] = '0';
  /* Field: Order: Promotion */
  $handler->display->display_options['fields']['promotion']['id'] = 'promotion';
  $handler->display->display_options['fields']['promotion']['table'] = 'orders';
  $handler->display->display_options['fields']['promotion']['field'] = 'promotion';
  $handler->display->display_options['fields']['promotion']['label'] = 'Sale';
  $handler->display->display_options['fields']['promotion']['precision'] = '0';
  /* Field: Order: Total_all_amount */
  $handler->display->display_options['fields']['total_all_amount']['id'] = 'total_all_amount';
  $handler->display->display_options['fields']['total_all_amount']['table'] = 'orders';
  $handler->display->display_options['fields']['total_all_amount']['field'] = 'total_all_amount';
  $handler->display->display_options['fields']['total_all_amount']['label'] = 'Total payment';
  $handler->display->display_options['fields']['total_all_amount']['precision'] = '0';
  /* Field: Order: Changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'orders';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Day';
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'd/m/Y H:i:s';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Order: Order ID */
  $handler->display->display_options['fields']['id_1']['id'] = 'id_1';
  $handler->display->display_options['fields']['id_1']['table'] = 'orders';
  $handler->display->display_options['fields']['id_1']['field'] = 'id';
  $handler->display->display_options['fields']['id_1']['label'] = 'See the bill';
  $handler->display->display_options['fields']['id_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['id_1']['alter']['text'] = '<a class="action" target="_blank" href="/app/print/[id]">See the bill</a>';
  $handler->display->display_options['fields']['id_1']['separator'] = '';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Order: Debt */
  $handler->display->display_options['filters']['debt']['id'] = 'debt';
  $handler->display->display_options['filters']['debt']['table'] = 'orders';
  $handler->display->display_options['filters']['debt']['field'] = 'debt';
  $handler->display->display_options['filters']['debt']['value']['value'] = '0';
  $export['order_list'] = $view;

  return $export;
}
