var     a:array [1..100] of longint;
        n,nbd,i,j,t,scs,dem,deml:longint;
        kt:boolean;
begin
        write('nhap chu so n:');
        readln(n);
        dem:=0;
        deml:=0;
        t:=0;
        kt:=true;
        while n <>0 do
        begin
        dem:=dem+1;
        a[dem]:=n mod 10;
        n:=n div 10;
        end;
        writeln('so luong cac chu so la:',dem);
        for i:=1 to dem do
        begin
        if a[i] mod 2<>0 then
        t:=t+a[i];
        end;
        for i:=1 to dem do t:=t+a[i];
        writeln('so chu so le la:',deml);
        writeln('tong cac chu so trong n la:',t);
        for i:=1 to dem div 2 do
        if a[i]<>a[dem-i+1] then
        begin
        kt:= false;
        break;
        end;
        if kt=true then write('n doi xung');
        if kt=false then write('n khong doi xung');
        readln
end.


