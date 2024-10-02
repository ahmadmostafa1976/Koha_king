<fieldset class="acqui_basket_add">
 <legend class="sr-only">إضافة طلب إلى السلة</legend>
 [% IF has_budgets %]
 <ul>
 <li>
 <form action="/cgi-bin/koha/catalogue/search.pl" method="get">
 <label>من تسجيلة موجودة بالفعل: <input type="text" name="q" size="25" />
 </label>
 <input class="submit" data-basketno="[% basketno | html %]" data-booksellerid="[% booksellerid | html %]" id="searchtoorder" type="submit" value="تقديم" />
 </form>
 </li>
 <li><a href="/cgi-bin/koha/acqui/newordersuggestion.pl?booksellerid=[% booksellerid | uri %]&amp;basketno=[% basketno | uri %]">من مقترح</a></li>
 <li><a href="/cgi-bin/koha/acqui/newordersubscription.pl?booksellerid=[% booksellerid | uri %]&amp;basketno=[% basketno | uri %]">من اشتراك</a></li>
 <li><a href="/cgi-bin/koha/acqui/neworderempty.pl?booksellerid=[% booksellerid | uri %]&amp;basketno=[% basketno | uri %]">من تسجيلة جديدة (فارغة)</a></li>
 <li><a href="/cgi-bin/koha/acqui/duplicate_orders.pl?basketno=[% basketno | uri %]">من طلبيات حالية (نسخ)</a></li>
 <li><a href="/cgi-bin/koha/acqui/z3950_search.pl?booksellerid=[% booksellerid | uri %]&amp;basketno=[% basketno | uri %]">من مصدر خارجي</a></li>
 [% IF ( CAN_user_tools_stage_marc_import ) %]<li><a href="/cgi-bin/koha/tools/stage-marc-import.pl?basketno=[% basketno | uri %]&amp;booksellerid=[% booksellerid | uri %]"> من ملف جديد</a></li>[% END %]
 <li><a href="/cgi-bin/koha/acqui/addorderiso2709.pl?booksellerid=[% booksellerid | uri %]&amp;basketno=[% basketno | uri %]"> من ملف مجهز</a></li>
 [% IF ( CAN_user_circulate ) %]<li><a href="/cgi-bin/koha/circ/reserveratios.pl?booksellerid=[% booksellerid | uri %]&amp;basketno=[% basketno | uri %]">من العناوين ذات أعلى معدلات الحجز</a></li>[% END %]
 </ul>
 [% ELSE %]
 <div class="dialog alert">
 <p>لا يمكنك إنشاء أي طلبيات إلا إذا قمت أولاً <a href="/cgi-bin/koha/admin/aqbudgetperiods.pl">بتعريف ميزانية وتمويل</a>.</p>
 </div>
 [% END %]
</fieldset>
