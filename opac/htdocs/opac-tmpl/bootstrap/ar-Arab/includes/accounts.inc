[%- BLOCK account_type_description -%]
 <span>
 [%- IF account.credit_type_code -%]
 [%- PROCESS credit_type_description credit_type_code = account.credit_type_code -%]
 [%- ELSIF account.debit_type_code -%]
 [%- PROCESS debit_type_description debit_type_code = account.debit_type_code -%]
 [%- END -%]
 [%- PROCESS account_status_description account=account -%]
 </span>
[%- END -%]

[%- BLOCK debit_type_description -%]
 [%- SWITCH debit_type_code -%]
 [%- CASE 'ACCOUNT'          -%]<span>رسم إنشاء الحساب</span>
 [%- CASE 'ACCOUNT_RENEW'    -%]<span>رسم تجديد الحساب</span>
 [%- CASE 'ARTICLE_REQUEST'  -%]<span>رسم طلب المقال</span>
 [%- CASE 'LOST'             -%]<span>مادة ضائعة</span>
 [%- CASE 'MANUAL'           -%]<span>رسم يدوي</span>
 [%- CASE 'NEW_CARD'         -%]<span>بطاقة جديدة</span>
 [%- CASE 'OVERDUE'          -%]<span>غرامة</span>
 [%- CASE 'PROCESSING'       -%]<span>رسم معالجة مادة ضائعة</span>
 [%- CASE 'RENT'             -%]<span>رسم الإيجار</span>
 [%- CASE 'RENT_DAILY'       -%]<span>رسم التأجير اليومي</span>
 [%- CASE 'RENT_RENEW'       -%]<span>تجديد مادة الإيجار</span>
 [%- CASE 'RENT_DAILY_RENEW' -%]<span>تجديد مادة الإيجار اليومي</span>
 [%- CASE 'RESERVE'          -%]<span>رسم الحجز</span>
 [%- CASE 'RESERVE_EXPIRED'  -%]<span>الحجز في الانتظار لمدة طويلة</span>
 [%- CASE 'PAYOUT'           -%]<span>الدفع من المكتبة إلى المستفيد</span>
 [%- CASE 'VOID'             -%]<span>لقد تم إبطال الائتمان</span>
 [%- CASE                    -%]<span>[% debit_type.description | html %]</span>
 [%- END -%]
[%- END -%]

[%- BLOCK credit_type_description -%]
 [%- SWITCH credit_type_code -%]
 [%- CASE 'CANCELLATION' -%]<span>رسم ملغي</span>
 [%- CASE 'CREDIT'       -%]<span>رصيد دائن</span>
 [%- CASE 'DISCOUNT'     -%]<span>الخصم</span>
 [%- CASE 'FORGIVEN'     -%]<span>معفو عنه</span>
 [%- CASE 'LOST_FOUND'   -%]<span>رد رسم المادة الضائعة</span>
 [%- CASE 'OVERPAYMENT'  -%]<span>استرداد المدفوعات الزائدة</span>
 [%- CASE 'PAYMENT'      -%]<span>المدفوعات</span>
 [%- CASE 'PROCESSING_FOUND' -%]<span>استرداد رسوم معالجة مادة ضائعة</span>
 [%- CASE 'PURCHASE'     -%]<span>شراء</span>
 [%- CASE 'REFUND'       -%]<span>استرداد الأموال</span>
 [%- CASE 'WRITEOFF'     -%]<span>شطب</span>
 [%- CASE                -%]<span>[% credit_type.description | html %]</span>
 [%- END -%]
[%- END -%]

[%- BLOCK account_status_description -%]
 [%- SWITCH account.status -%]
 [%- CASE 'UNRETURNED' -%]<span> (متراكم)</span>
 [%- CASE 'RETURNED'   -%]<span> (تمت إعادته)</span>
 [%- CASE 'REPLACED'   -%]<span> (تم استبداله)</span>
 [%- CASE 'REFUNDED'   -%]<span> (تم رد المبلغ)</span>
 [%- CASE 'FORGIVEN'   -%]<span> (معفو عنه)</span>
 [%- CASE 'VOID'       -%]<span> (لاغ)</span>
 [%- CASE 'LOST'       -%]<span> (ضائعة)</span>
 [%- CASE 'CANCELLED'  -%]<span> (ملغي)</span>
 [%- CASE              -%]
 [%- END -%]
[%- END -%]
