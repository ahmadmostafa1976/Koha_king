[% IF patron.borrowernumber %]
<table id="ill-requests-patron-[% patron.borrowernumber | html %]">
[% ELSIF batch.id %]
<table id="ill-requests-batch-[% batch.id | html %]">
[% ELSE %]
<table id="ill-requests">
[% END %]
 <thead>
 <tr id="ill_requests_header">
 <th scope="col">معرّف الطلب</th>
 <th scope="col">الدفعة</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="author"         data-related-search-on="value">مؤلف</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="title"         data-related-search-on="value">عنوان</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="article_title" data-related-search-on="value">عنوان المقال</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="issue"         data-related-search-on="value">عدد</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="volume"        data-related-search-on="value">مجلد</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="year"          data-related-search-on="value">عام</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="pages"         data-related-search-on="value">صفحات</th>
 <th scope="col" data-datatype="related-object" data-related="extended_attributes" data-related-key="type" data-related-value="type"          data-related-search-on="value">نوع الطلب</th>
 <th scope="col">معرّف الطلبية</th>
 <th scope="col">المستفيد</th>
 <th scope="col">معرف التسجيلة الببليوغرافية</th>
 <th scope="col">المكتبة</th>
 <th scope="col">حالة</th>
 <th scope="col" class="placed_formatted">موضوع على</th>
 <th scope="col" class="updated_formatted">تم التحديث في</th>
 <th scope="col">قام بالرد</th>
 <th scope="col" class="completed_formatted">اكتمل في</th>
 <th scope="col">عنوان URL للوصول</th>
 <th scope="col">التكلفة</th>
 <th scope="col">السعر المدفوع</th>
 <th scope="col">التعليقات</th>
 <th scope="col">ملاحظات الأوباك</th>
 <th scope="col">ملاحظات الموظف</th>
 <th scope="col">نهاية خلفية</th>
 <th scope="col" class="actions"></th>
 </tr>
 </thead>
 <tbody id="illview-body">
 </tbody>
</table>