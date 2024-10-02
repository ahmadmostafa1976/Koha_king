[% USE HtmlId %]
<div id="menu">
 <ul>
 [% IF ( accounting ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=accounting" title="الحسابات">الحسابات</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=accounting" title="الحسابات">الحسابات</a>
 [% END %]
 [% IF ( acquisitions ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=acquisitions" title="التزويد">التزويد</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=acquisitions" title="التزويد">التزويد</a>
 [% END %]
 </li>

 [% IF ( admin ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=admin" title="الإدارة">الإدارة</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=admin" title="الإدارة">الإدارة</a>
 [% END %]
 </li>

 [% IF ( authorities ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=authorities" title="التحكم في الاستناد">الاستنادات</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=authorities" title="التحكم في الاستناد">الاستنادات</a>
 [% END %]
 </li>

 [% IF ( cataloguing ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=cataloguing" title="الفهرسة">الفهرسة</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=cataloguing" title="الفهرسة">الفهرسة</a>
 [% END %]
 </li>

 [% IF ( circulation ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=circulation" title="الإعارة">الإعارة</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=circulation" title="الإعارة">الإعارة</a>
 [% END %]
 </li>

 [% IF ( enhanced_content ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=enhanced_content" title="إعدادات المحتوى المحسَّن">محتوى محسَّن</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=enhanced_content" title="إعدادات المحتوى المحسَّن">محتوى محسَّن</a>
 [% END %]
 </li>

 [% IF ( erm ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=erm" title="إدارة الموارد الإلكترونية">إدارة الموارد الإلكترونية</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=erm" title="إدارة الموارد الإلكترونية">إدارة الموارد الإلكترونية</a>
 [% END %]
 </li>

 [% IF ( i18n_l10n ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=i18n_l10n" title="التدويل والترجمة">اللغات العالمية</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=i18n_l10n" title="التدويل والترجمة">اللغات العالمية</a>
 [% END %]
 </li>

 [% IF ( interlibrary_loans ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=interlibrary_loans" title="الإعارات البينية">الإعارات البينية</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=interlibrary_loans" title="الإعارات البينية">الإعارات البينية</a>
 [% END %]
 </li>

 [% IF ( local_use ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/systempreferences.pl">استخدام محلي</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/systempreferences.pl">استخدام محلي</a>
 [% END %]
 </li>

 [% IF ( logs ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=logs" title="سجلات العمليات">سجلات</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=logs" title="سجلات العمليات">سجلات</a>
 [% END %]
 </li>

 [% IF ( opac ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=opac" title="فهرس الوصول المباشر للجمهور (الأوباك)">أوباك</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=opac" title="فهرس الوصول المباشر للجمهور (الأوباك)">أوباك</a>
 [% END %]
 </li>

 [% IF ( patrons ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=patrons" title="المستفيدين">المستفيدين</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=patrons" title="المستفيدين">المستفيدين</a>
 [% END %]
 </li>

 [% IF ( preservation ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=preservation" title="الحفظ">الحفظ</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=preservation" title="الحفظ">الحفظ</a>
 [% END %]
 </li>

 [% IF ( searching ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=searching" title="جاري البحث">جاري البحث</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=searching" title="جاري البحث">جاري البحث</a>
 [% END %]
 </li>

 [% IF ( serials ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=serials" title="الدوريات">الدوريات</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=serials" title="الدوريات">الدوريات</a>
 [% END %]
 </li>

 [% IF ( staff_interface ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=staff_interface" title="واجهة الموظف">واجهة الموظف</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=staff_interface" title="واجهة الموظف">واجهة الموظف</a>
 [% END %]
 </li>

 [% IF ( tools ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=tools" title="الأدوات">الأدوات</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=tools" title="الأدوات">الأدوات</a>
 [% END %]
 </li>

 [% IF ( web_services ) %]
 <li class="active">
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=web_services" title="خدمات الويب">خدمات الويب</a>
 [% PROCESS subtabs  %]
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/preferences.pl?tab=web_services" title="خدمات الويب">خدمات الويب</a>
 [% END %]
 </li>
 </ul>
</div>

[% BLOCK subtabs %]
 [% UNLESS ( searchfield ) %]
 [% FOREACH TAB IN TABS %]
 <ul>
 [% FOREACH LINE IN TAB.LINES %]
 [% IF ( LINE.is_group_title ) %]
 <li><a class="pref_sublink" href="#[% TAB.tab_id | html %]_[% LINE.title | $HtmlId %]">[% LINE.title | html %]</a></li>
 [% END %]
 [% END %]
 </ul>
 [% END %]
 [% END %]
[% END %]
