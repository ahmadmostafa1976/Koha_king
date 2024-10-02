[% USE Koha %]
[% USE Branches %]
<div id="navmenu">
 <div id="navmenulist">
 <h5>الإعارة</h5>
 <ul>
 <li>
 <a href="/cgi-bin/koha/circ/circulation.pl">إعارة</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/circ/returns.pl">رد</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/circ/renew.pl">تجديد</a>
 </li>
 [% IF ( CAN_user_superlibrarian || CAN_user_loggedinlibrary ) %]
 <li>
 [% IF Koha.Preference('UseCirculationDesks') %]
 <a href="/cgi-bin/koha/circ/set-library.pl">ضبط المكتبة والمكتب</a>
 [% ELSE %]
 <a href="/cgi-bin/koha/circ/set-library.pl">اضبط المكتبة</a>
 [% END %]
 </li>
 [% ELSIF Koha.Preference('UseCirculationDesks') %]
 <li>
 <a href="/cgi-bin/koha/circ/set-library.pl">ضبط المكتب</a>
 </li>
 [% END %]
 [% IF ( fast_cataloging && CAN_user_editcatalogue_fast_cataloging ) %]
 <li>
 <a href="/cgi-bin/koha/cataloguing/addbiblio.pl?frameworkcode=FA"> الفهرسة السريعة</a>
 </li>
 [% END %]
 [% IF ( Koha.Preference('AllowCheckoutNotes') && CAN_user_circulate_manage_checkout_notes ) %]
 <li>
 <a href="/cgi-bin/koha/circ/checkout-notes.pl">ملاحظات الإعارة</a>
 </li>
 [% END %]
 [% IF Koha.Preference('OnSiteCheckouts') %]
 <li>
 <a href="/cgi-bin/koha/circ/on-site_checkouts.pl">إعارات في الموقع في الانتظار</a>
 </li>
 [% END %]
 </ul>

 <h5>حجوزات</h5>
 <ul>
 <li>
 <a href="/cgi-bin/koha/circ/view_holdsqueue.pl">صف الحجوزات</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/circ/pendingreserves.pl">حجوزات للسحب</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/circ/waitingreserves.pl">حجز في انتظار الالتقاط</a>
 </li>
 [% IF ( Koha.Preference('CurbsidePickup') && CAN_user_circulate_manage_curbside_pickups ) %]
 <li>
 <a href="/cgi-bin/koha/circ/curbside_pickups.pl">التقاطات جانبية</a>
 </li>
 [% END %]
 <li>
 <a href="/cgi-bin/koha/circ/reserveratios.pl">معدلات الحجز</a>
 </li>
 </ul>

 [% IF Koha.Preference('UseRecalls') and CAN_user_recalls %]
 <h5>الاستدعاءات</h5>
 <ul>
 <li>
 <a href="/cgi-bin/koha/recalls/recalls_queue.pl" title="كل الاستدعاءات النشطة">صف الاستدعاءات</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/recalls/recalls_to_pull.pl" title="الاستدعاءات التي يمكن ملؤها ولكن لم يتم وضعها في الانتظار">استدعاءات للسحب</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/recalls/recalls_overdue.pl" title="المواد المستدعاة التي تجاوزت موعد إعادتها">استدعاءات متأخرة</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/recalls/recalls_waiting.pl" title="المواد المستدعاة في انتظار الالتقاط">استدعاءات في انتظار الالتقاط</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/recalls/recalls_old_queue.pl" title="استدعاءات غير نشطة">استدعاءات قديمة</a>
 </li>
 </ul>
 [% END %]

 [% IF Koha.Preference('ArticleRequests') %]
 <h5>طلب المستفيد</h5>
 <ul>
 <li>
 <a href="/cgi-bin/koha/circ/article-requests.pl">طلبات المقال</a>
 </li>
 </ul>
 [% END %]

 <h5>النقل</h5>
 <ul>
 [% IF !Koha.Preference('IndependentBranchesTransfers') || CAN_user_superlibrarian %]
 <li>
 <a href="/cgi-bin/koha/circ/branchtransfers.pl">النقل</a>
 </li>
 [% END %]
 [% IF Koha.Preference('StockRotation') %]
 <li>
 <a href="/cgi-bin/koha/circ/transfers_to_send.pl">انتقالات للإرسال</a>
 </li>
 [% END %]
 <li>
 <a href="/cgi-bin/koha/circ/transferstoreceive.pl">انتقالات للاستلام</a>
 </li>
 </ul>

 [% IF ( CAN_user_circulate_overdues_report ) %]
 <h5>متأخرات</h5>
 <ul>
 <li>
 <a href="/cgi-bin/koha/circ/overdue.pl" title="تحذير: هذا التقرير كثيف المصادر على النظام مع الأعداد الكبيرة من المواد المتأخرة.">متأخرات</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/circ/branchoverdues.pl" title="مقصور على مكتبتك. انظر مساعدة التقارير للمزيد من التفاصيل.">المتأخرات مع غرامات</a>
 </li>
 </ul>
 [% END %]
 </div>
</div>
