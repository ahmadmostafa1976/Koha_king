[% USE raw %]
[% USE Koha %]
[% PROCESS 'html_helpers.inc' %]

<!-- prefs-admin-search.inc -->
[% WRAPPER tabs id="header_search" %]
 [% WRAPPER tab_panels %]
 [% WRAPPER tab_panel tabname="syspref_search" bt_active= 1 %]
 <form action="/cgi-bin/koha/admin/preferences.pl" method="get">
 <input type="hidden" name="tab" value="[% last_tab | html %]" />
 <input type="hidden" name="op" value="search" />

 <div class="form-title">
 <label class="control-label" for="searchfield"><span class="control-text">بحث تفضيلات النظام</span> <i class="fa fa-fw fa-cogs" aria-hidden="true"></i></label>
 </div>

 <div class="form-content">
 <input class="head-searchbox form-control" id="searchfield" name="searchfield" placeholder="بحث تفضيلات النظام" type="text" value="">
 </div>

 <button aria-label="بحث" type="submit"><i class="fa fa-arrow-right"></i></button>
 </form>
 [% END # /tab_panel %]

 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 [% INCLUDE 'patron-search-box.inc' %]
 [% END %]

 [% IF ( CAN_user_catalogue ) %]
 [% INCLUDE 'catalogue-search-box.inc' %]
 [% END %]
 [% END # /tab_panels %]

 [% WRAPPER tabs_nav %]
 [% WRAPPER tab_item tabname= "syspref_search" bt_active= 1 %]
 <i class="fa fa-fw fa-cogs" aria-hidden="true"></i> <span class="tab-title">بحث تفضيلات النظام</span>
 [% END %]
 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 [% WRAPPER tab_item tabname= "circ_search" %]
 <i class="fa fa-upload" aria-hidden="true"></i> <span class="tab-title">إعارة</span>
 [% END %]
 [% END %]
 [% IF ( CAN_user_catalogue ) %]
 [% WRAPPER tab_item tabname= "catalog_search" %]
 <i class="fa fa-fw fa-search" aria-hidden="true"></i> <span class="tab-title">بحث الفهرس</span>
 [% END %]
 [% END %]
 [% END # /tabs_nav %]
[% END # /WRAPPER tabs %]
<!-- /prefs-admin-search.inc -->
