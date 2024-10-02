[% USE Koha %]
[% USE KohaPlugins %]
[% IF ( ( Koha.Preference( 'opacuserlogin' ) == 1 ) && loggedinusername ) %]
 <div id="menu">
 <ul>
 [% IF ( userview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-user.pl">ملخص</a></li>
 [% IF ( OPACFinesTab ) %]
 [% IF ( accountview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-account.pl">الرسوم</a></li>
 [% END %]

 [% IF ( userupdateview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-memberentry.pl">تفاصيل شخصية</a></li>

 [% IF Koha.Preference('PrivacyPolicyConsent') || KohaPlugins.feature_enabled('patron_consent_type') %]
 [% IF consentview %]<li class="active">[% ELSE %]<li>[% END %]
 <a href="/cgi-bin/koha/opac-patron-consent.pl">الموافقات</a>
 </li>
 [% END %]

 [% IF Koha.Preference( 'TagsEnabled' ) == 1 %]
 [% IF ( tagsview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-tags.pl?mine=1">الوسوم</a></li>
 [% END %]

 [% IF logged_in_user.category.effective_change_password %]
 [% IF ( passwdview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-passwd.pl">تغيير كلمة المرور</a></li>
 [% END %]

 [% IF EnableOpacSearchHistory %]
 [% IF ( searchhistoryview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-search-history.pl">سِجل البحث</a></li>
 [% END %]

 [% IF ( opacreadinghistory ) %]
 [% IF ( readingrecview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-readingrecord.pl">سِجل الإعارة</a></li>
 [% IF ( OPACPrivacy ) %]
 [% IF ( privacyview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-privacy.pl">الخصوصية</a></li>
 [% END %]
 [% END # / opacreadinghistory %]

 [% IF Koha.Preference('OPACHoldsHistory') == 1 %]
 [% IF ( holdshistoryview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-holdshistory.pl">سجل الحجوزات</a></li>
 [% END %]

 [% IF Koha.Preference('UseRecalls') %]
 [% IF ( recallsview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-recalls.pl">سجل الاستدعاءات</a>
 [% END %]

 [% IF ( suggestion ) %]
 [% IF ( suggestionsview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-suggestions.pl">مقترحات الشراء</a></li>
 [% END %]

 [% IF ( EnhancedMessagingPreferences ) %]
 [% IF Koha.Preference( 'EnhancedMessagingPreferencesOPAC' ) || Koha.Preference('TranslateNotices') %]
 [% IF ( messagingview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-messaging.pl">المراسلات</a></li>
 [% END %]
 [% END %]

 [% IF Koha.Preference( 'virtualshelves' ) == 1 %]
 [% IF ( listsview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-shelves.pl?op=list">قوائم</a></li>
 [% END %]

 [% IF Koha.Preference( 'RoutingSerials' ) && logged_in_user && logged_in_user.get_routing_lists.count %]
 [% IF ( routinglistsview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-routing-lists.pl">قوائم التمرير</a></li>
 [% END %]

 [% IF Koha.Preference( 'useDischarge' ) == 1 %]
 [% IF ( dischargeview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-discharge.pl">قم بطلب إخلاء الطرف</a></li>
 [% END %]

 [% IF Koha.Preference( 'ILLModule' ) == 1 %]
 [% IF ( illrequestsview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-illrequests.pl">طلبات الإعارة البينية</a></li>
 [% END %]

 [% IF Koha.Preference( 'CurbsidePickup' ) %]
 [% IF ( ermview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-curbside-pickups.pl">عمليات الالتقاط الجانبية</a></li>
 [% END %]

 [% IF logged_in_user.alert_subscriptions.count %]
 [% IF ( alertsview ) %]
 <li class="active">
 [% ELSE %]
 <li>
 [% END %]
 <a href="/cgi-bin/koha/opac-alert-subscriptions.pl">تنبيه الاشتراكات ( [% logged_in_user.alert_subscriptions.count | html %] )</a></li>
 [% END %]

 </ul>
 </div>
[% END %]
