<?php
class StockInViewsController extends EntityDefaultViewsController {
  function views_data() {
    $data = parent::views_data();
    $data['stock_in']['created']['field']['handler'] = 'views_handler_field_date';
    $data['stock_in']['created']['filter']['handler'] = 'views_handler_filter_date';
    return $data;
  }
}
class StockOutViewsController extends EntityDefaultViewsController {
  function views_data() {
    $data = parent::views_data();
    $data['stock_out']['created']['field']['handler'] = 'views_handler_field_date';
    $data['stock_out']['created']['filter']['handler'] = 'views_handler_filter_date';
    return $data;
  }
}
