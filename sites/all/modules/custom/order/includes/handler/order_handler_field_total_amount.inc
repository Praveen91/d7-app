<?php
class order_handler_field_total_amount extends views_handler_field
{
  /**
   * Render the area
   */
  function render($empty = FALSE)
  {
    $amount = order_get_total_amount($this->view->result);
    $element = array(
      '#id' => $this->view->name . '-total-amount-area',
      '#attributes' => array(
        'class' => explode(' ', $this->options['css_class']),
        'style' => $this->options['css_style'],
      ),
      '#children' => $amount,
    );
    return theme('container', array('element' => $element));
  }
}
