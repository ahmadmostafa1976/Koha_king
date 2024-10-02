[% USE Koha %]
[% USE Branches %]
[% PROCESS 'html_helpers.inc' %]
<ol>
 <li><label for="title">العنوان: </label> <input type="text" name="title" id="title" value="[% filters.title | html %]" /></li>
 <li><label for="author">المؤلف: </label> <input type="text" name="author" id="author" value="[% filters.author | html %]" /></li>
 <li><label for="isbn">ردمك: </label> <input type="text" name="isbn" id="isbn" value="[% filters.isbn | html %]" /></li>
 <li><label for="isbn">تدمد: </label> <input type="text" name="issn" id="issn" value="[% filters.issn | html %]" /></li>
 [% IF Koha.Preference('marcflavour') == 'UNIMARC' %]
 <li><label for="ean">EAN: </label> <input type="text" name="ean" id="ean" value="[% filters.ean | html %]" /></li>
 [% END %]
 <li><label for="name">المزود: </label> <input type="text" name="name" id="name" value="[% filters.name | html %]" /></li>
 <li><label for="basket">السلة: </label> <input type="text" name="basket" id="basket" value="[% filters.basket | html %]" /></li>
 <li><label for="internalnote">ملاحظة داخلية: </label> <input type="text" name="internalnote" id="internalnote" value="[% filters.internalnote | html %]" /></li>
 <li><label for="vendornote">ملاحظة المزود: </label> <input type="text" name="vendornote" id="vendornote" value="[% filters.vendornote | html %]" /></li>
 <li><label for="basket_creators">تم إنشاء السلة بواسطة: </label>
 <input autocomplete="off" id="find_patron" type="text" class="noEnterSubmit" />
 <div>
 <div id="basket_creators" style="float:left;"></div>
 </div>
 </li>
 <li>
 <label for="managing_library">إدارة المكتبة: </label>
 <select name="managing_library" id="managing_library">
 <option value="">أي مكتبة</option>
 [% PROCESS options_for_libraries libraries => Branches.all(selected => '') %]
 </select>
 </li>
 <li><label for="booksellerinvoicenumber ">رقم فاتورة المزود: </label> <input type="text" name="booksellerinvoicenumber" id="booksellerinvoicenumber" value="[% filters.booksellerinvoicenumber | html %]" /></li>
 <li>
 <label for="basketgroupname">مجموعة السلة:</label>
 <input type="text" name="basketgroupname" id="basketgroupname" value="[% filters.basketgroupname | html %]" />
 </li>
 [% INCLUDE 'additional-fields-entry.inc' available=available_additional_fields values=additional_field_filters wrap_fieldset=0 %]
 <li>
 <label for="ordernumber">سطر الطلبية:</label>
 <input type="text" name="ordernumber" id="ordernumber" value="[% filters.ordernumber | html %]" />
 <label class="yesno" for="search_children_too">
 [% IF filters.search_children_too %]
 <input type="checkbox" name="search_children_too" id="search_children_too" value="1" checked="checked" />
 [% ELSE %]
 <input type="checkbox" name="search_children_too" id="search_children_too" value="1" />
 [% END %] عرض الأطفال أيضا </label>
 </li>

 <li>
 <label for="orderstatus">حالة الطلبية: </label>
 <select name="orderstatus" id="orderstatus">
 [% IF filters.orderstatus == "" %]
 <option value="">أي حالة ما عدا ملغي</option>
 [% ELSE %]
 <option value="" selected="selected">أي حالة ما عدا ملغي</option>
 [% END %]
 [% IF filters.orderstatus == "any" %]
 <option value="any" selected="selected">أي حالة</option>
 [% ELSE %]
 <option value="any">أي حالة</option>
 [% END %]
 [% IF filters.orderstatus == "new" %]
 <option value="new" selected="selected">جديد</option>
 [% ELSE %]
 <option value="new">جديد</option>
 [% END %]
 [% IF filters.orderstatus == "ordered" %]
 <option value="ordered" selected="selected">مطلوب</option>
 [% ELSE %]
 <option value="ordered">مطلوب</option>
 [% END %]
 [% IF filters.orderstatus == "partial" %]
 <option value="partial" selected="selected">مستلم جزئيا</option>
 [% ELSE %]
 <option value="partial">مستلم جزئيا</option>
 [% END %]
 [% IF filters.orderstatus == "complete" %]
 <option value="complete" selected="selected">مستلم</option>
 [% ELSE %]
 <option value="complete">مستلم</option>
 [% END %]
 [% IF filters.orderstatus == "cancelled" %]
 <option value="cancelled" selected="selected">ملغي</option>
 [% ELSE %]
 <option value="cancelled">ملغي</option>
 [% END %]
 </select>
 <label class="yesno" for="is_standing">
 [% IF filters.is_standing %]
 <input type="checkbox" name="is_standing" id="is_standing" value="1" checked="checked" />
 [% ELSE %]
 <input type="checkbox" name="is_standing" id="is_standing" value="1" />
 [% END %] طلبية قائمة </label>
 </li>
 <li>
 <label for="fund">التمويل: </label>
 <select name="budget" id="fund">
 <option value="">كل التمويلات</option>
 [% FOREACH bp_loo IN bp_loop %]
 <optgroup label="[% bp_loo.budget_period_description | html %]">
 [% FOREACH h_loo IN bp_loo.hierarchy %]
 [% IF h_loo.budget_id == filters.budget %]
 <option type="text" value="[% h_loo.budget_id | html %]" branchcode="[% h_loo.budget_branchcode | html %]" selected="selected">
 [% ELSE %]
 <option type="text" value="[% h_loo.budget_id | html %]" branchcode="[% h_loo.budget_branchcode | html %]">
 [% END %]
 [% h_loo.budget_display_name | html %]
 </option>
 [% END %]
 </optgroup>
 [% END %]
 </select>
 </li>

 <li><label for="from">من: </label>
 <input type="text" size="10" id="from" name="from" value="[% filters.from_placed_on | html %]" class="flatpickr" data-date_to="to" />
 <div class="hint">[% INCLUDE 'date-format.inc' %]</div>
 </li>
 <li><label for="to">إلى: </label>
 <input type="text" size="10" id="to" name="to" value="[% filters.to_placed_on | html %]" class="flatpickr" />
 <div class="hint">[% INCLUDE 'date-format.inc' %]</div>
 </li>
</ol>
