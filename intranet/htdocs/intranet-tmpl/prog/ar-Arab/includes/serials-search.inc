[% USE raw %]
[% USE Koha %]
[% PROCESS 'html_helpers.inc' %]
<!-- serials-search.inc -->
[% WRAPPER tabs id="header_search" %]
 [% WRAPPER tab_panels %]
 [% WRAPPER tab_panel tabname="subscription_search" bt_active= 1 %]
 <form action="/cgi-bin/koha/serials/serials-search.pl" method="get">
 [% IF ( routing ) %]
 <input type="hidden" name="routing" value="[% routing | html %]" />
 [% END %]
 <input type="hidden" name="searched" value="1" />

 <div class="form-title">
 <label class="control-label" for="ISSN_filter"><span class="control-text">بحث الاشتراكات</span> <i class="fa fa-fw fa-book" aria-hidden="true"></i></label>
 </div>

 <div class="form-content">
 <input class="form-control" id="ISSN_filter" name="ISSN_filter" placeholder="تدمد" size="11" type="text" value="[% ISSN_filter | html %]" />

 [% IF (UNIMARC) %]
 <input type="text" class="form-control" placeholder="EAN" size="11" name="EAN_filter" id="EAN_filter" value="[% EAN_filter | html %]" />
 [% END %]

 <input class="form-control" id="title_filter" name="title_filter" placeholder="عنوان" size="11" type="text" value="[% title_filter | html %]" />
 <button class="form-extra-content-toggle" title="المزيد من الخيارات" type="button"><i class="form-extra-content-icon fa-solid fa-sliders" aria-hidden="true"></i></button>

 </div>

 <button aria-label="بحث" type="submit"><i class="fa fa-arrow-right"></i></button>
 <div class="form-extra-content">
 <div>
 <label for="callnumber_filter">رقم الاستدعاء:</label>
 <input class="form-control" id="callnumber_filter" name="callnumber_filter" placeholder="رقم الاستدعاء" type="text" value="[% callnumber_filter | html %]">
 </div>
 <div>
 <label for="publisher_filter">الناشر:</label>
 <input class="form-control" id="publisher_filter" name="publisher_filter" placeholder="الناشر" type="text" value="[% publisher_filter | html %]">
 </div>
 <div>
 <label for="bookseller_filter">المزود:</label>
 <input class="form-control" id="bookseller_filter" name="bookseller_filter" placeholder="المزود" type="text" value="[% bookseller_filter | html %]">
 </div>
 <div>
 <a href="/cgi-bin/koha/serials/serials-search.pl">بحث متقدم</a>
 </div>
 </div> <!-- /.form-extra-content -->
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
 [% WRAPPER tab_item tabname= "subscription_search" bt_active= 1 %]
 <i class="fa fa-book" aria-hidden="true"></i> <span class="tab-title">بحث الاشتراكات</span>
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
<!-- /serials-search.inc -->
