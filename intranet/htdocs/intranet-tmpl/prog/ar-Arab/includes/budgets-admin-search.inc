[% USE raw %]
[% USE Koha %]
[% PROCESS 'html_helpers.inc' %]
[% USE Branches %]
<!-- budgets-admin-search.inc -->
[% WRAPPER tabs id="header_search" %]
 [% WRAPPER tab_panels %]
 [% WRAPPER tab_panel tabname="budgets_search" bt_active= 1 %]
 <form action="/cgi-bin/koha/admin/aqbudgets.pl" method="get">
 <input type="hidden" name="budget_period_id" value="[% budget_period_id | html %]" />

 <div class="form-title">
 <label class="control-label" for="filter_budgetname"><span class="control-text">بحث التمويلات</span> <i class="fa-solid fa-fw fa-credit-card"></i></label>
 </div>

 <div class="form-content">
 <input class="query form-control" id="filter_budgetname" name="filter_budgetname" placeholder="بحث التمويلات" type="text" value="[% filter_budgetname | html %]" />

 <button class="form-extra-content-toggle" title="المزيد من الخيارات" type="button"><i class="form-extra-content-icon fa-solid fa-sliders" aria-hidden="true"></i></button>
 </div>

 <button aria-label="بحث" type="submit"><i class="fa fa-arrow-right"></i></button>

 <div class="form-extra-content">
 <label for="filter_budgetbranch">المكتبة</label>

 <select name="filter_budgetbranch" id="filter_budgetbranch" class="form-control">
 <option value="">كل المكتبات</option>
 [% FOREACH branchloo IN Branches.all( selected => selected_branchcode ) %]
 [% IF branchloo.selected %]
 <option value="[% branchloo.branchcode | html %]" selected="selected">[% branchloo.branchname | html %]</option>
 [% ELSE %]
 <option value="[% branchloo.branchcode | html %]" >[% branchloo.branchname | html %]</option>
 [% END %]
 [% END %]
 </select>
 </div>
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
 [% WRAPPER tab_item tabname= "budgets_search" bt_active= 1 %]
 <i class="fa-solid fa-fw fa-credit-card"></i> <span class="tab-title">بحث التمويلات</span>
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
<!-- /budgets-admin-search.inc -->
