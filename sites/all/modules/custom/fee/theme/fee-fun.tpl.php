<div class="header-total-fun">
  <h3>Tổng doanh thu: <?php print number_format($fun['total']); ?> đ</h3>
</div>
<table>
  <tr><th>Hóa đơn</th><th>Ngày</th><th>Tổng cộng</th></tr>
  <tbody>
  <?php if($fun['orders']): ?>
  <?php foreach($fun['orders'] as $order): ?>
        <tr>
          <td><?php print $order->id; ?></td>
          <td><?php print format_date($order->created,'custom','d/m/Y'); ?></td>
          <td><?php print number_format($order->total_all_amount); ?> đ</td>
        </tr>
  <?php endforeach;?>
  <?php endif; ?>
  </tbody>
</table>
