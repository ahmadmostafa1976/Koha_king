 <select name="overlay_action" id="overlay_action">
 [% IF ( overlay_action_replace ) %]
 <option value="replace"  selected="selected">
 [% ELSE %]
 <option value="replace">
 [% END %] إستبدال التسجيلة الحالية مع التسجيلة الواردة</option>
 [% IF ( overlay_action_create_new ) %]
 <option value="create_new" selected="selected">
 [% ELSE %]
 <option value="create_new">
 [% END %] إضافة تسجيلة واردة</option>
 [% IF ( overlay_action_ignore ) %]
 <option value="ignore" selected="selected">
 [% ELSE %]
 <option value="ignore">
 [% END %] تجاهل التسجيلة الواردة (التي ربما لا تزال موادها قيد المعالجة)</option>
 </select>
