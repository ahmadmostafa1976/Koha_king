[% IF ( no_add ) %]
 <div class="dialog alert">
 <h3>لا يمكن إضافة مستفيد</h3>
 [% IF ( no_branches ) %]
 <p><strong>لا توجد مكتبات معرفة. </strong>[% IF ( CAN_user_parameters ) %]<a href="/cgi-bin/koha/admin/branches.pl">يرجى إضافة مكتبة</a>.[% ELSE %]يجب على المدير أن  يحدد على الأقل مكتبة واحدة .[% END %]</p>
 [% END %]
 [% IF ( no_categories ) %]
 <p><strong>لا توجد فئات مستفيدين معرفة. </strong>[% IF ( CAN_user_parameters ) %]<a href="/cgi-bin/koha/admin/categories.pl">يرجى إضافة فئة مستفيد</a>.[% ELSE %]يجب على المدير تحديد تصنيف واحد على الأقل لكل مستفيد .[% END %]</p>
 [% END %]
 </div>
[% END %]
