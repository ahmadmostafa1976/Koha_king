 [% IF item_action_ignore AND num_items == 0 %] لم يتم العثور على أي مواد أثناء التجهيز <input type ="hidden" name="item_action" value="ignore">
 [% ELSE %]
 <select name="item_action" id="item_action">
 [% IF ( item_action_always_add ) %]
 <option value="always_add" selected="selected">
 [% ELSE %]
 <option value="always_add">
 [% END %] قم دائماً بإضافة مواد</option>
 [% IF ( item_action_add_only_for_matches ) %]
 <option value="add_only_for_matches" selected="selected">
 [% ELSE %]
 <option value="add_only_for_matches">
 [% END %] إضافة المواد فقط إذا تم العثور على تسجيلة بيبلوغرافية متطابقة</option>
 [% IF ( item_action_add_only_for_new ) %]
 <option value="add_only_for_new" selected="selected">
 [% ELSE %]
 <option value="add_only_for_new">
 [% END %] قم بإضافة المواد فقط في حالة عدم العثور على تسجيلات بيبلوغرافية متطابقة</option>
 [% IF ( item_action_replace ) %]
 <option value="replace" selected="selected">
 [% ELSE %]
 <option value="replace">
 [% END %] استبدال المواد إذا تم العثور على تسجيلة بيبلوغرافية مضاهية (للمواد الموجودة فقط)</option>
 [% IF ( item_action_ignore ) %]
 <option value="ignore" selected="selected">
 [% ELSE %]
 <option value="ignore">
 [% END %] تجاهل المواد</option>
 </select>
 [% END %]
