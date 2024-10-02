<div id="toolbar" class="btn-toolbar">
 [% IF ( budget_period_id ) %]
 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-toggle="dropdown"><i class="fa fa-plus"></i> جديد <span class="caret"></span></button>
 <ul class="dropdown-menu">
 <li><a href="/cgi-bin/koha/admin/aqbudgetperiods.pl?op=add_form">ميزانية جديدة</a></li>
 [% IF ( budget_period_locked || !CAN_user_acquisition_budget_add_del ) %]
 <li class="disabled">
 <a data-placement="left" data-toggle="tooltip" href="#" title="الميزانية مقفلة">تمويل جديد لـ [% budget_period_description | html %]</a>
 </li>
 [% ELSE %]
 <li>
 <a href="/cgi-bin/koha/admin/aqbudgets.pl?op=add_form&amp;budget_period_id=[% budget_period_id | uri %]">تمويل جديد لـ [% budget_period_description | html %]</a>
 </li>
 [% END %]
 </ul>
 </div>

 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-toggle="dropdown"><i class="fa-solid fa-pencil" aria-hidden="true"></i> تحرير <span class="caret"></span></button>
 <ul class="dropdown-menu">
 <li><a href="/cgi-bin/koha/admin/aqbudgetperiods.pl?op=add_form&amp;budget_period_id=[% budget_period_id | uri %]">تحرير الميزانية [% budget_period_description | html %]</a></li>
 <li><a href="/cgi-bin/koha/admin/aqbudgetperiods.pl?op=duplicate_form&amp;budget_period_id=[% budget_period_id | uri %]">نسخ الميزانية [% budget_period_description | html %]</a></li>
 </ul>
 </div>

 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-toggle="dropdown"><i class="fa-solid fa-pencil" aria-hidden="true"></i> تخطيط <span class="caret"></span></button>
 <ul class="dropdown-menu">
 [% IF ( CAN_user_acquisition_planning_manage ) %]
 <li>
 [% ELSE %]
 <li class="disabled">
 [% END %]
 <a href="/cgi-bin/koha/admin/aqplan.pl?budget_period_id=[% budget_period_id | uri %]&amp;authcat=MONTHS">تخطيط حسب الأشهر</a></li>
 [% IF ( CAN_user_acquisition_planning_manage ) %]
 <li>
 [% ELSE %]
 <li class="disabled">
 [% END %]
 <a href="/cgi-bin/koha/admin/aqplan.pl?budget_period_id=[% budget_period_id | uri %]&amp;authcat=BRANCHES">تخطيط حسب المكتبات</a></li>
 [% IF ( CAN_user_acquisition_planning_manage ) %]
 <li>
 [% ELSE %]
 <li class="disabled">
 [% END %]
 <a href="/cgi-bin/koha/admin/aqplan.pl?budget_period_id=[% budget_period_id | uri %]&amp;authcat=ITEMTYPES">تخطيط حسب أنواع المواد</a></li>
 [% FOREACH auth_cats_loo IN auth_cats_loop %]
 [% IF ( CAN_user_acquisition_planning_manage ) %]
 <li>
 [% ELSE %]
 <li class="disabled">
 [% END %]
 <a href="/cgi-bin/koha/admin/aqplan.pl?budget_period_id=[% budget_period_id | uri %]&amp;authcat=[% auth_cats_loo | uri %]">تخطيط بواسطة [% auth_cats_loo | html %]</a>
 </li>
 [% END %]
 </ul>
 </div>

 [% ELSE %]
 <div class="btn-group"><a class="btn btn-default" id="newrootbudget" href="/cgi-bin/koha/admin/aqbudgetperiods.pl?op=add_form"><i class="fa fa-plus"></i> ميزانية جديدة</a></div>
 [% END %]

</div>
