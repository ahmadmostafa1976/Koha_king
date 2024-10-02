[% IF op == "batch_list" %]
<h1>
 <span>عرض دفعات طلبات الإعارة البينية</span>
</h1>
<div class="page-section">
 <h2>تفاصيل لكل الدفعات</h2>
 <table id="ill-batch-requests">
 <thead>
 <tr id="ill-batch-header">
 <th scope="col">معرف الدفعة</th>
 <th scope="col">الاسم</th>
 <th scope="col">عدد الطلبات</th>
 <th scope="col">حالة</th>
 <th scope="col">المستفيد</th>
 <th scope="col">المكتبة</th>
 <th scope="col"></th>
 </tr>
 </thead>
 <tbody id="ill-batch-body">
 </tbody>
 </table>
</div>
[% END %]