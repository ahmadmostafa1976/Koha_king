<div id="navmenu">
 <div id="navmenulist">
 <h5>الدوريات</h5>
 <ul>
 [% IF ( subscriptionid ) %]
 <li><a href="/cgi-bin/koha/serials/serials-collection.pl?subscriptionid=[% subscriptionid | uri %]">مجموعة الدورية</a></li>
 [% UNLESS closed %]
 [% IF ( routing && CAN_user_serials_routing ) %]
 [% IF ( hasRouting ) %]
 <li><a href="/cgi-bin/koha/serials/routing.pl?subscriptionid=[% subscriptionid | uri %]">تحرير قائمة التمرير</a></li>
 [% ELSE %]
 <li><a href="/cgi-bin/koha/serials/routing.pl?subscriptionid=[% subscriptionid | uri %]&amp;op=new">إنشاء قائمة التمرير</a></li>
 [% END %]
 [% END %]
 [% END %]
 [% END %]

 [% IF ( CAN_user_serials_claim_serials ) %]
 <li><a href="/cgi-bin/koha/serials/claims.pl">المطالبات</a></li>
 [% END %]
 [% IF ( CAN_user_serials_check_expiration ) %]
 <li><a href="/cgi-bin/koha/serials/checkexpiration.pl">التحقق من الانتهاء</a></li>
 [% END %]
 <li>
 <a href="/cgi-bin/koha/serials/subscription-frequencies.pl">
 إدارة التواترات </a>
 </li>
 <li>
 <a href="/cgi-bin/koha/serials/subscription-numberpatterns.pl">
 إدارة أنماط الترقيم </a>
 </li>
 [% IF Koha.Preference('Mana') == 1 %]
 <li><a href="/cgi-bin/koha/serials/serials-search.pl?mana=1">البحث على مانا</a></li>
 [% END %]
 [% IF CAN_user_serials_edit_subscription && CAN_user_parameters_manage_additional_fields %]
 <li>
 <a href="/cgi-bin/koha/admin/additional-fields.pl?tablename=subscription">إدارة حقول الاشتراك</a>
 </li>
 [% END %]
 </ul>

 [% IF ( CAN_user_reports ) %]
 <h5>التقارير</h5>
 <ul>
 <li><a href="/cgi-bin/koha/reports/serials_stats.pl">معالج إحصائيات الدوريات</a></li>
 </ul>
 [% END %]

 </div>
</div>
