[% USE raw %]
[% PROCESS 'i18n.inc' %]
[% SET footerjs = 1 %]
[% INCLUDE 'doc-head-open.inc' %]
[% IF ( ! method ) %]
 [% method = 'tool'; %]
[% END %]
<title>[% FILTER collapse %]
 [% IF ( plugin_title ) %]
 [% plugin_title | html %] &rsaquo;
 [% END %]
 [% t("Plugins") | html %] &rsaquo;
 [% IF ( method == 'tool' ) %]
 [% t("Tools") | html %]
 [% ELSE %]
 [% t("Administration") | html %]
 [% END %] &rsaquo;
 [% t("Koha") | html %]
 [% END %]</title>
[% INCLUDE 'doc-head-close.inc' %]
</head>

<body id="plugins_run_tool" class="plugins">
[% WRAPPER 'header.inc' %]
 [% INCLUDE 'prefs-admin-search.inc' %]
[% END %]

[% WRAPPER 'sub-header.inc' %]
 [% WRAPPER breadcrumbs %]
 [% WRAPPER breadcrumb_item %]
 [% IF ( method == 'tool' ) %]
 <a href="/cgi-bin/koha/tools/tools-home.pl">الأدوات</a>
 [% ELSE %]
 <a href="/cgi-bin/koha/admin/admin-home.pl">الإدارة</a>
 [% END %]
 [% END %]
 [% WRAPPER breadcrumb_item %]
 <a href="/cgi-bin/koha/plugins/plugins-home.pl">برامج مساعدة</a>
 [% END %]
 [% WRAPPER breadcrumb_item bc_active= 1 %]
 [% IF ( plugin_title ) %][% plugin_title | html %][% ELSE %]<span>البرنامج المساعد</span>[% END %]
 [% END %]
 [% END #/ WRAPPER breadcrumbs %]
[% END #/ WRAPPER sub-header.inc %]

<div class="main container-fluid">
 <div class="row">
 <div class="col-sm-10 col-sm-push-2">
 <main>
 [% content | $raw %]
 </main>
 </div> <!-- /.col-sm-10.col-sm-push-2 -->

 <div class="col-sm-2 col-sm-pull-10">
 <aside>
 [% IF ( method == 'tool' ) %]
 [% INCLUDE 'tools-menu.inc' %]
 [% ELSE %]
 [% INCLUDE 'admin-menu.inc' %]
 [% END %]
 </aside>
 </div> <!-- /.col-sm-2.col-sm-pull-10 -->
 </div> <!-- /.row -->

[% INCLUDE 'intranet-bottom.inc' %]
