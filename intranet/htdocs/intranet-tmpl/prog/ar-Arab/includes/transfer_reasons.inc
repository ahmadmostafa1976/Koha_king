[%- BLOCK transfer_reason -%]
 [%- SWITCH transfer.reason -%]
 [%- CASE 'Manual'                    -%]<span>يدوي</span>
 [%- CASE 'StockrotationAdvance'      -%]<span>تدوير المخزون المتقدم</span>
 [%- CASE 'StockrotationRepatriation' -%]<span>إعادة تدوير المخزون</span>
 [%- CASE 'ReturnToHome'              -%]<span>العودة التلقائية إلى الرئيسية</span>
 [%- CASE 'ReturnToHolding'           -%]<span>العودة التلقائية إلى المقتنية</span>
 [%- CASE 'RotatingCollection'        -%]<span>مجموعة التدوير</span>
 [%- CASE 'Reserve'                   -%]<span>حجز</span>
 [%- CASE 'LostReserve'               -%]<span>ضاع الحجز</span>
 [%- CASE 'CancelReserve'             -%]<span>تم إلغاء الحجز</span>
 [%- CASE                             -%]<span>[% transfer.reason | html %]</span>
 [%- END -%]
[%- END -%]
