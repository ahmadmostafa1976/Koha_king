[% USE raw %]
[% USE Koha %]
[% PROCESS 'html_helpers.inc' %]
<!-- desks-admin-search.inc -->
[% WRAPPER tabs id="header_search" %]
 [% WRAPPER tab_panels %]
 [% WRAPPER tab_panel tabname="desk_search" bt_active= 1 %]
 <form action="[% script_name|html %]" method="get">
 <div class="form-title">
 <label class="control-label" for="search_desk_name"><span class="control-text">بحث المكاتب</span> <i class="fa fa-fw fa-desktop" aria-hidden="true"></i></label>
 </div>

 <div class="form-content">
 <input class="head-searchbox form-control" id="search_desk_name" name="desk_name" placeholder="بحث المكاتب" size="40" type="text" value="[% searchfield|html %]" />
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
 <li role="presentation" class="active">
 [% WRAPPER tab_item tabname= "desk_search" bt_active= 1 %]
 <i class="fa fa-fw fa-desktop" aria-hidden="true"></i> <span class="tab-title">بحث المكاتب</span>
 [% END %]
 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 [% WRAPPER tab_item tabname= "circ_search" %]
 <i class="fa fa-fw fa-upload" aria-hidden="true"></i> <span class="tab-title">إعارة</span>
 [% END %]
 [% END %]
 [% IF ( CAN_user_catalogue ) %]
 [% WRAPPER tab_item tabname= "catalog_search" %]
 <i class="fa fa-fw fa-search" aria-hidden="true"></i> <span class="tab-title">بحث الفهرس</span>
 [% END %]
 [% END %]
 [% END # /tabs_nav %]
[% END # /WRAPPER tabs %]
<!-- /desks-admin-search.inc -->
