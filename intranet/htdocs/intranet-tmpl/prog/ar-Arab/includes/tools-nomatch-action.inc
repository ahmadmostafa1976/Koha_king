 <select name="nomatch_action" id="nomatch_action">
 [% IF ( nomatch_action_create_new ) %]
 <option value="create_new" selected="selected">
 [% ELSE %]
 <option value="create_new">
 [% END %] إضافة تسجيلة واردة</option>
 [% IF ( nomatch_action_ignore ) %]
 <option value="ignore" selected="selected">
 [% ELSE %]
 <option value="ignore">
 [% END %] تجاهل التسجيلة الواردة</option>
 </select>
