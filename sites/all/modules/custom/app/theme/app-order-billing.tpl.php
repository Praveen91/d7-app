
<div class="billing=wrapper">
  <h2>Payment of invoices</h2>

  <div style="border-bottom: 1px solid #c3c3c3" class="header-billing-info">
    <h3><?php print $table->name ?></h3>
    <p><i>Day <?php print date('d/m/Y',$order->start) ?></i></p>
    <p><i>Start Time: </i><?php print date('H:i', $order->start); ?></p>
    <p><i>Time is over: </i><?php print date('H:i', time()) ?></p>
    <p><i>Time to use: </i><?php print app_time_in_use($table) ?></p>
  </div>
  <div class="items-list-billing">
    <?php if ($items): ?>
      <h3>Menu</h3>
      <table>
        <tr>
          <th>ID</th>
          <th>Menu</th>
          <th>Unit price</th>
          <th>Quantity</th>
          <th>Total</th>
        </tr>
        <tbody>
        <?php foreach ($items as $item): ?>
            <tr>
              <td><?php print $item->id ?></td>
              <td><?php print $item->cook_table_items->name; ?></td>
              <td><?php print number_format($item->cook_table_items->price); ?> đ</td>
              <td><?php print $item->quantity; ?></td>
              <td><?php print number_format($item->total_amount); ?> đ</td>
            </tr>
        <?php endforeach; ?>
        </tbody>
      </table>
    <?php endif; ?>
  </div>
  <div class="total-amount" style="border-bottom: 1px solid #c3c3c3; margin-top: 20px">
    <h5>Money /h: <?php print number_format($table->price) ?> đ</h5>
    <h3>Total: <?php print number_format(app_get_current_total($table)) ?> đ</h3>
  </div>
</div>
