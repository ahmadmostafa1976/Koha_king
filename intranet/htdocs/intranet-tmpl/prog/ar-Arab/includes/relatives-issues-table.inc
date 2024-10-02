[% USE Koha %]
[% IF ( relatives_issues_count ) %]
 <table id="relatives-issues-table" style="width: 100% !Important;">
 <thead>
 <tr>
 <th scope="col">تاريخ الاستحقاق (غير منسق،مخفي)</th>
 <th scope="col">تاريخ الإستحقاق</th>
 <th scope="col">عنوان</th>
 <th scope="col">نوع المادة على مستوى التسجيلة</th>
 <th scope="col">نوع المادة</th>
 <th scope="col">المجموعة</th>
 <th scope="col">الموقع</th>
 <th scope="col">معار في (مخفي، غير منسق)</th>
 <th scope="col">الإعارة في</th>
 <th scope="col">تمت الإعارة من</th>
 <th scope="col">رقم الاستدعاء</th>
 <th scope="col">رقم النسخة</th>
 <th scope="col">فرض رسم</th>
 <th scope="col">غرامة</th>
 <th scope="col">السعر</th>
 <th scope="col">المستفيد</th>
 </tr>
 </thead>
 </table>
[% END %]
