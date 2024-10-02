[% BLOCK asksysadmin %]<span>يرجى تحقق مدير النظام من سجل الأخطاء للمزيد من التفاصيل.</span>[% END %]
[% BLOCK b_batch %]<span>الدفعة: </span>[% END %]
[% BLOCK b_patronlist %]<span>قوائم المستفيد: </span>[% END %]
[% BLOCK b_patronnumber %]<span>رقم المستفيد:  </span>[% END %]
[% BLOCK b_layout %]<span>التخطيط: </span>[% END %]
[% BLOCK b_template %]<span>القالب: </span>[% END %]

[% IF ( error || error_pdferr )  %]
<div class="dialog alert">
 <p>
 <strong>تحذير :</strong>
 [% IF error_pdferr %]<span>لقد حد خطأ أثناء إنشاء ملف PDF </span>
 [% IF error_errnocards %]<span>لم يتم إنشاء بطاقات (دفعة أو قائمة فارغة؟) </span>[% END %]
 [% IF error_errba %][% INCLUDE b_batch %]<span class="ex">[%- error_errba | html -%]</span>[% END %]
 [% IF error_errpl %][% INCLUDE b_patronlist %]<span class="ex">[%- error_errpl | html -%]</span>][% END %]
 [% IF error_errpt %][% INCLUDE b_patronnumber %]<span class="ex">[%- error_errpt | html -%]</span>[% END %]
 [% IF error_errlo %][% INCLUDE b_layout %]<span class="ex">[%- error_errlo | html -%]</span>[% END %]
 [% IF error_errtpl %][% INCLUDE b_template %]<span class="ex">[%- error_errtpl | html -%]</span>[% END %]
 [% INCLUDE asksysadmin %]
 [% END %]

 [% IF ( error == 101 ) %]
 [% IF ( card_element ) %]<span>قامت قاعدة البيانات بإعادة رسالة خطأ أثناء حفظ [% card_element | html %] [% element_id | html %]. </span>
 [% ELSE %]<span>قامت قاعدة البيانات بإعادة رسالة خطأ أثناء محاولة إجراء عملية الحفظ. </span>[% END %][% INCLUDE asksysadmin %]
 [% ELSIF ( error == 102 ) %]
 [% IF ( card_element ) %]<span>قامت قاعدة البيانات بإعادة رسالة خطأ أثناء حذف [% card_element | html %] [% element_id | html %]. </span>
 [% ELSIF ( image_ids ) %]<span>قامت قاعدة البيانات بإعادة رسالة خطأ أثناء حذف [% image_ids | html %]. </span>
 [% ELSE %]<span>قامت قاعدة البيانات بإعادة رسالة خطأ أثناء محاولة إجراء عملية الحذف. </span>[% END %][% INCLUDE asksysadmin %]
 [% ELSIF ( error == 201 ) %]
 [%IF ( element_id ) %]<span>تمت محاولة إجراء عملية غير مدعومة في [% card_element | html %] [% element_id | html %]. </span>
 [% ELSE %]<span>تمت محاولة إجراء عملية غير مدعومة. </span>[% END %][% INCLUDE asksysadmin %]
 [% ELSIF ( error == 202 ) %]
 <span>لقد حدث خطأ. </span>[% INCLUDE asksysadmin %]
 [% ELSIF ( error == 203 ) %]
 <span>تم تقديم رمز مكتبة غير موجود أو غير صحيح. يرجى التأكد من ضبط المكتبة. </span><a href="/cgi-bin/koha/circ/set-library.pl">اضبط المكتبة</a>
 [% ELSIF ( error == 301 ) %]
 <span>لقد حدث خطأ أثناء محاولة تحميل ملف الصورة. </span>[% INCLUDE asksysadmin %]
 [% ELSIF ( error == 302 ) %]
 <span>حجم الصورة يتجاوز 2 ميجابايت. يرجى تصغير الحجم وإعادة الاستيراد مرة أخرى. </span>
 [% ELSIF ( error == 303 ) %]
 <span>تتيح حصة صورة قاعدة البيانات حالياً حداً أقصى لتخزين الصور في أي مرة واحدة من [% image_limit | html %]  صورة. يرجى حذف إحدى الصور أو أكثر لتحرير مساحة الحصة. </span>
 [% ELSIF ( error == 304 ) %]
 <span>توجد بالفعل صورة تحمل الاسم '[% IMAGE_NAME | html %]'.</span>
 [% ELSIF ( error == 401 ) %]
 <span>لقد حدث خطأ ولم تتم إضافة أي مواد للدفعة [% batch_id | html %] </span>[% INCLUDE asksysadmin %]
 [% ELSIF ( error == 402 ) %]
 <span>لم تتم إضافة مواد بسبب عدم ضبط المكتبة. يرجى ضبط مكتبتك أولاً قبل إضافة المواد للدفعة. </span><a href="/cgi-bin/koha/circ/set-library.pl">اضبط المكتبة</a>
 [% ELSIF ( error == 403 ) %]
 <span>لقد حدث خطأ ولم تتم إزالة المواد من الدفعة [% batch_id | html %] </span>[% INCLUDE asksysadmin %]
 [% ELSIF ( error == 404 ) %]
 <span>لقد حدث خطأ ولم يتم حذف الدفعة [% batch_id | html %] </span>[% INCLUDE asksysadmin %]
 [% ELSIF ( error == 405 ) %]
 <span>لقد حدث خطأ ولم يتم الغاء تكرار الدفعة [% batch_id | html %] بالكامل. </span>
 [% END %]
 </p>
</div>
[% END %]
