[%# To select all include with selectall = 1 %]
<div class="branchselector">
 <p><a href="#" id="checkall"> <i class="fa fa-check"></i> تحديد الكل</a> | <a href="#" id="checknone"> <i class="fa fa-times"></i> مسح الكل</a></p>
 <div class="branchgridrow">
 [% FOREACH branch IN branches %]
 <div class="branchgriditem">
 [% IF branch.selected || (selectall == 1) %]
 <input id="branch_[% branch.branchcode | html %]" class="branch_select" type="checkbox" name="branch" value="[% branch.branchcode | html %]" checked="checked" />
 [% ELSE %]
 <input id="branch_[% branch.branchcode | html %]" class="branch_select" type="checkbox" name="branch" value="[% branch.branchcode | html %]" />
 [% END %]

 <label for="branch_[% branch.branchcode | html %]">[% branch.branchname | html %]</label>
 </div>
 [% IF loop.count() % 4 == 0 && !loop.last() %]
 </div>
 <div class="branchgridrow">
 [% END %]
 [% END %]
 </div>
</div>
