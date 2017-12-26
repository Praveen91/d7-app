
<div id="cook-table-wrapper">
  <div id="table-list-cook-table" style="border-bottom: 1px solid #c3c3c3; margin-bottom: 20px;"
       class="large-12 list-table columns">
    <h3>Menu table for <?php print $table->name; ?></h3>
    <table class="table-list-wrapper">
      <tr>
        <th>ID</th>
        <th>Menu</th>
        <th>Unit price</th>
        <th>Quantity</th>
        <th>Make money</th>
        <th>Delete</th>
      </tr>
      <tbody>
      <?php if ($cook_tables): ?>
        <?php foreach ($cook_tables as $cook_table): ?>
          <tr class="order-item-<?php print $cook_table->order_item_id; ?>">
            <td><?php print $cook_table->order_item_id; ?></td>
            <td><?php print $cook_table->name; ?></td>
            <td><?php print number_format($cook_table->price); ?> đ</td>
            <td><?php print $cook_table->qty; ?></td>
            <td><?php print number_format($cook_table->total); ?> đ</td>
            <td><a data="<?php print $cook_table->order_item_id ?>" class="delete-item">
                <img width="20"
                     height="auto"
                     src="<?php print base_path() . drupal_get_path('module', 'app') ?>/image/delete-icon.gif"/>
              </a>
            </td>
          </tr>
        <?php endforeach; ?>
      <?php endif; ?>
      </tbody>
    </table>
    <div class="total-amount"><h5>Total: <?php print $total; ?> INR</h5></div>
  </div>
</div>
