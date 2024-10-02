[% USE KohaSpan %]
[% BLOCK report %]
 [% IF job.status == 'finished' %]
 <div class="dialog message">
 تم تسمية الإحصائيات بأسماء مستعارة. </div>
 [% ELSIF job.status == 'cancelled' %]
 <div class="dialog message">
 تم إلغاء إطلاق الاسم المستعار. </div>
 [% ELSE %]
 <div class="dialog message">
 تعيين الاسم المستعار في الانتظار. </div>
 [% END %]
[% END %]

[% BLOCK detail %]
 <div class="dialog message">
 التسمية البديلة </div>
[% END %]

[% BLOCK js %]
[% END %]
