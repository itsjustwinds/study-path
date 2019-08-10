var
        a:array [1..100] of longint;
        i,n,t,spt:longint;
begin
        write('nhap so luong phan tu cua day:');
        readln(n);
        t:=0;
        spt:=0;
        for i:=1 to n do
        begin
                write('nhap cac so:');
                readln(a[i]);
        end;
        for i:=1 to n do
        if a[i] mod 3=0 then
        begin
        t:=t+a[i];
        spt:=spt+1;
        writeln(a[i]);
        end;
        write('trung binh cong cac uoc cua 3 la:',t/spt:8:2);
        readln
end.


