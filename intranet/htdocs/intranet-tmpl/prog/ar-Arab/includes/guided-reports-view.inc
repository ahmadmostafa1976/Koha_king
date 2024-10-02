[% USE Koha %]
<div id="navmenu">
<div id="navmenulist">

<h5>شغّل التقارير</h5>
<ul>
 [% IF ( CAN_user_reports_execute_reports ) %]<li><a href="/cgi-bin/koha/reports/guided_reports.pl?op=list">تقارير محفوظة</a></li>[% END %]
</ul>
<h5>قاموس التقارير</h5>
<ul>
<li><a href="/cgi-bin/koha/reports/dictionary.pl">عرض القاموس</a></li>
</ul>
<h5>موارد مفيدة</h5>
<ul>
<li><a href="http://wiki.koha-community.org/wiki/SQL_Reports_Library" target="blank">كوها تقارير المكتبة</a></li>
[% SET koha_version = Koha.Version %]
[% IF koha_version.development %]
 <li><a href="http://schema.koha-community.org/main" target="blank">مخطط قاعدة البيانات لكوها</a></li>
[% ELSE %]
 <li><a href="http://schema.koha-community.org/[% koha_version.major | uri %]_[% koha_version.minor | uri %]" target="blank">مخطط قاعدة البيانات لكوها</a></li>
[% END %]
</ul>
</div>
</div>
