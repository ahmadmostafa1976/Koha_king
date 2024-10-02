[% FOR m IN messages %]
 [% SWITCH m.code %]
 [% CASE 'success_on_insert_library' %]
 <div class="alert alert-success">تم إنشاء المكتبة!</div>
 [% CASE 'error_on_insert_library' %]
 <div class="alert alert-danger">المكتبة موجودة بالفعل ولا يمكن تعديلها!</div>
 [% CASE 'success_on_insert_category' %]
 <div class="alert alert-success">تم إنشاء فئة المستفيد!</div>
 [% CASE 'error_on_insert_category' %]
 <div class="alert alert-danger">فئة المستفيد موجودة بالفعل ولا يمكن تعديلها!</div>
 [% CASE 'success_on_insert_patron' %]
 <div class="alert alert-success">تم إنشاء حساب المدير!</div>
 [% CASE 'error_on_insert_patron' %]
 <div class="alert alert-danger">The patron was not created! The card number or username already exists.</div>
 [% CASE 'ERROR_cardnumber_already_exists' %]
 <div class="alert alert-danger">رقم البطاقة قيد الاستخدام بالفعل.</div>
 [% CASE 'ERROR_cardnumber_length' %]
 <div class="alert alert-danger">طول رقم البطاقة غير صحيح.</div>
 [% CASE 'ERROR_password_mismatch' %]
 <div class="alert alert-danger">كلمتي المرور غير متطابقتين.</div>
 [% CASE 'success_on_insert_itemtype' %]
 <div class="alert alert-success">تم إنشاء نوع مادة جديد!</div>
 [% CASE 'error_on_insert_itemtype' %]
 <div class="alert alert-danger">نوع المادة موجود بالفعل!</div>
 [% CASE 'success_on_insert_circ_rule' %]
 <div class="alert alert-success">تم إنشاء قاعدة الإعارة!</div>
 [% CASE 'error_on_insert_circ_rule' %]
 <div class="alert alert-danger">لم يتم إنشاء قاعدة الإعارة!</div>
 [% CASE 'ERROR_password_too_short' %]
 <div class="alert alert-danger">لم يتم إنشاء المستفيد، كلمة المرور التي تم إدخالها قصيرة جدا</div>
 [% CASE 'ERROR_password_too_weak' %]
 <div class="alert alert-danger">لم يتم إنشاء المستفيد، كلمة المرور التي تم إدخالها ضعيفة جدا، يجب أن تحتوي كلمة المرور على الأقل على حرف كبير، وحرف صغير، ورقم واحد</div>
 [% CASE 'ERROR_password_has_whitespaces' %]
 <div class="alert alert-danger">لم يتم إنشاء المستفيد، ربما تحتوي كلمة المرور على مسافات</div>
 [% CASE %][% message | html %]
 [% END %]
[% END %]
