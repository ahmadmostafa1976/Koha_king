[% USE Koha %]

<div id="navmenu">
 <div id="navmenulist">

 <h5>التقارير الموجهة</h5>
 <ul>
 <li><a href="/cgi-bin/koha/reports/guided_reports.pl">التقارير الموجهة</a></li>
 [% IF ( CAN_user_reports_create_reports ) %]
 <li><a href="/cgi-bin/koha/reports/guided_reports.pl?op=add_form">أنشئ جديد</a></li>
 [% END %]
 [% IF ( CAN_user_reports_execute_reports ) %]
 <li><a href="/cgi-bin/koha/reports/guided_reports.pl?op=list">استخدم المحفوظ</a></li>
 [% END %]
 [% IF ( CAN_user_reports_create_reports ) %]
 <li><a href="/cgi-bin/koha/reports/guided_reports.pl?op=add_form_sql">إنشاء من SQL</a></li>
 [% END %]
 </ul>

 <h5>معالجات الاحصائيات</h5>
 <ul>
 <li><a href="/cgi-bin/koha/reports/acquisitions_stats.pl">التزويد</a></li>
 <li><a href="/cgi-bin/koha/reports/borrowers_stats.pl">المستفيدين</a></li>
 <li><a href="/cgi-bin/koha/reports/catalogue_stats.pl">الفهرس</a></li>
 <li><a href="/cgi-bin/koha/reports/issues_stats.pl">الإعارة</a></li>
 <li><a href="/cgi-bin/koha/reports/serials_stats.pl">الدوريات</a></li>
 <li><a href="/cgi-bin/koha/reports/cash_register_stats.pl">سجل نقدي</a></li>
 <li><a href="/cgi-bin/koha/reports/reserves_stats.pl">حجوزات</a></li>
 </ul>

 [% IF plugins_enabled %]
 <h5>برامج التقرير المساعدة</h5>
 <ul>
 <li><a href="/cgi-bin/koha/plugins/plugins-home.pl?method=report">برامج التقرير المساعدة</a></li>
 </ul>
 [% END %]

 <h5>القوائم العُليا</h5>
 <ul>
 <li><a href="/cgi-bin/koha/reports/bor_issues_top.pl">المستفيدون الأكثر إستعارةً</a></li>
 <li><a href="/cgi-bin/koha/reports/cat_issues_top.pl">المواد الأكثر إعارة</a></li>
 </ul>

 <h5>غير نشط</h5>
 <ul>
 <li><a href="/cgi-bin/koha/reports/borrowers_out.pl">المستفيدون الذين ليس لديهم إعارات</a></li>
 <li><a href="/cgi-bin/koha/reports/catalogue_out.pl">مواد بدون إعارات</a></li>
 </ul>


 <h5>أخرى</h5>
 <ul>
 <li><a href="/cgi-bin/koha/reports/itemslost.pl">مواد ضائعة</a></li>
 <li><a href="/cgi-bin/koha/reports/orders_by_fund.pl">الطلبيات بواسطة التمويل</a></li>
 <li><a href="/cgi-bin/koha/reports/catalog_by_itemtype.pl">فهرسة بواسطة نوع المادة</a></li>
 <li><a href="/cgi-bin/koha/reports/issues_avg_stats.pl">متوسط وقت الإعارة</a></li>
 </ul>
 </div>
</div>
