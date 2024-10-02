[% USE raw %]
[% USE Koha %]
[% PROCESS 'html_helpers.inc' %]
[% USE Branches %]
<!-- catalogue-search-box.inc -->
[% WRAPPER tab_panel tabname="catalog_search" bt_active= bs_tab_active %]
 <form action="/cgi-bin/koha/catalogue/search.pl"  method="get" id="cat-search-block">
 <div class="form-title">
 <label class="control-label" for="search-form"><span class="control-text">بحث الفهرس</span> <i class="fa fa-fw fa-search" aria-hidden="true"></i></label>
 </div>

 <div class="form-content">
 [% IF ( Koha.Preference('RetainCatalogSearchTerms') ) %]
 <input class="query form-text head-searchbox form-control" id="search-form" name="q" placeholder="قم بإدخال الكلمات المفتاحية للبحث" size="20" title="قم بإدخال المصطلحات التي تريد أن تبحث عنها." type="text" value="[% ms_value | html %]" />
 [% ELSE %]
 <input class="query form-text head-searchbox form-control" id="search-form" name="q" placeholder="قم بإدخال الكلمات المفتاحية للبحث" size="20" title="قم بإدخال المصطلحات التي تريد أن تبحث عنها." type="text" />
 [% END %]

 [% IF Koha.Preference('IntranetCatalogSearchPulldown') || Koha.Preference('IntranetAddMastheadLibraryPulldown') %]
 <button class="form-extra-content-toggle" title="المزيد من الخيارات" type="button"><i class="form-extra-content-icon fa-solid fa-sliders" aria-hidden="true"></i></button>
 [% END %]
 </div>
 <button aria-label="بحث" type="submit"><i class="fa fa-arrow-right"></i></button>

 <div class="form-extra-content">
 [% IF ( Koha.Preference('IntranetCatalogSearchPulldown') ) %]
 <div>
 <label for="idx">بحث الفهرس</label>
 [% INCLUDE 'search_indexes.inc' $header_pulldown = 1 %]
 </div>
 [% END %]

 [% IF ( Koha.Preference('IntranetAddMastheadLibraryPulldown') ) %]
 <div>
 <label for="select_library">المكتبة</label>
 <select id="select_library" name="limit">
 <option value="">كل المكتبات</option>
 [% PROCESS options_for_libraries prefix => "branch:" libraries => Branches.all( selected => branch_limit ) %]
 </select>
 </div>
 [% END %]
 </div>
 </form>
[% END # /tab_panel %]
<!-- /catalogue-search-box.inc -->

