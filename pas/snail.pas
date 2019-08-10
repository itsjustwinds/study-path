uses crt;
var
        a,v,b,ngay,tam,vtbn,vtbd:longint;
begin   clrscr;
        write('nhap van toc');
        readln(a);
        write('nhap quang duong khi truot xuong');
        readln(b);
        write('nhap chieu cao cua cay');
        readln(v);
        if a<b then write('con sen se khong len dc cay');
        ngay:=0;
        tam:=0;
        vtbn:=0;
        vtbd:=0;
        while vtbn<v do
        begin
                tam:=vtbd;
                vtbn:=vtbd+a;
                vtbd:=vtbn-b;
                ngay:=ngay+1;
        end;
        if vtbn=v then write('so ngay cua sen len cay la: ',ngay);
        if vtbn>v then write('so ngay cua sen len cay la: ',ngay-1+((v-tam)/a):0:2);
        readln
end.
