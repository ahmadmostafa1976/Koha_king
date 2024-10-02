<div id="multi_receiving" class="modal" tabindex="-1" role="dialog" aria-labelledby="multi_receiving_label" aria-hidden="true">
 <div class="modal-dialog">
 <div class="modal-content">
 <form action="/cgi-bin/koha/serials/serials-collection.pl" method="post">
 [% INCLUDE 'csrf-token.inc' %]
 <div class="modal-body">
 <fieldset class="rows">
 <legend>استلام متعدد</legend>
 <ol>
 <li>
 <label for="nbissues" class="required">كم عدداً ترغب في استلامه؟</label>
 <input type="text"  size="25" id="nbissues" name="nbissues" required="required" />
 <li>
 <li>
 <label for="date_received_today">ضبط تاريخ الاستلام إلى تاريخ اليوم؟</label>
 <input type="checkbox" id="date_received_today" name="date_received_today" />
 </li>
 </ol>
 <input type="hidden" name="op" value="cud-gennext" />

 [%# subscriptionidlist is used from serials-collection, subscriptionid is used from serils-edit %]
 <input type="hidden" name="subscriptionid" value="[% subscriptionidlist || subscriptionid | html %]" />
 </fieldset>
 </div>

 <div class="modal-footer">
 <a href="#" class="cancel" data-dismiss="modal" aria-hidden="true">إلغاء</a>
 <input class="btn btn-default approve" type="submit" value="صحيح" />
 </div>
 </form>
 </div>
 </div>
</div>
