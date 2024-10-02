<!-- member-search-box.inc -->
[% USE Branches %]
[% USE Categories %]
[% USE Koha %]
[% PROCESS 'patronfields.inc' %]
[% IF CAN_user_borrowers_edit_borrowers || CAN_user_borrowers_list_borrowers %]
 [%- SET searchtype = searchtype || Koha.Preference('DefaultPatronSearchMethod') -%]
 [% WRAPPER tab_panel tabname="patron_search" bt_active= bs_tab_active %]
 <form method="get" action="/cgi-bin/koha/members/member.pl">
 <input type="hidden" name="quicksearch" value="1" />

 <div class="form-title">
 <label class="control-label" for="searchmember"><span class="control-text">بحث المستفيدين</span> <i class="fa fa-fw fa-id-card" aria-hidden="true"></i></label>
 </div>

 <div class="form-content">
 [% IF ( Koha.Preference('RetainPatronsSearchTerms') ) %]
 <input class="head-searchbox form-control" id="searchmember" name="searchmember" placeholder="إدخال رقم بطاقة المستفيد أو الاسم الجزئي" size="25" type="text" value="[% searchmember | html %]" />
 [% ELSE %]
 <input class="head-searchbox form-control" id="searchmember" name="searchmember" placeholder="إدخال رقم بطاقة المستفيد أو الاسم الجزئي" size="25" type="text" />
 [% END %]

 <button class="form-extra-content-toggle" title="المزيد من الخيارات" type="button"><i class="form-extra-content-icon fa-solid fa-sliders" aria-hidden="true"></i></button>
 </div>

 <button aria-label="بحث" type="submit"><i class="fa fa-arrow-right"></i></button>

 <div class="form-extra-content">
 <div>
 [% INCLUDE patron_fields_dropdown search_box=1 %]
 </div>

 <div>
 <label for="searchtype" class="control-label">نوع البحث</label>
 <select name="searchtype" id="searchtype" class="form-control">
 [% IF searchtype == 'starts_with' %]
 <option value='starts_with' selected='selected'>يبدأ بـ</option>
 <option value='contains'>يحتوي</option>
 [% ELSE %]
 <option value='starts_with'>يبدأ بـ</option>
 <option value='contains' selected='selected'>يحتوي</option>
 [% END %]
 </select>
 </div>

 <div>
 [% SET branches = Branches.all( selected => branchcode_filter, only_from_group => 1 ) %]
 <label for="branchcode" class="control-label">المكتبة</label>
 <select name="branchcode_filter" id="branchcode" class="form-control">
 [% IF branches.size != 1 %]
 <option value="">أي</option>
 [% END %]
 [% PROCESS options_for_libraries libraries => branches %]
 </select>
 </div>

 <div>
 [% SET categories = Categories.all() %]
 <label for="categorycode" class="control-label">فئة</label>
 <select name="categorycode_filter" id="categorycode" class="form-control">
 <option value="">أي</option>
 [% FOREACH category IN categories %]
 [% IF category.categorycode == categorycode_filter %]
 <option value="[% category.categorycode | html %]" selected="selected">[% category.description | html %]</option>
 [% ELSE %]
 <option value="[% category.categorycode | html %]">[% category.description | html %]</option>
 [% END %]
 [% END %]
 </select>
 </div>
 </div>
 </form>
 [% END # /tab_panel %]
[% END %]
<!-- /member-search-box.inc -->
