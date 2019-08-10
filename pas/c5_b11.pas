var
        a:array [1..100] of longint;
        i,n,j,tam,dem,demx,k,m:longint;
begin
        write('nhap so luong phan tu');
        readln(n);
        demx:=0;
        for i:=1 to n do
        begin
        write('nhap gia tri');
        readln(a[i]);
        end;
        for i:=1 to n do
        for j:=n downto i do
        if a[i]>a[j] then
        begin
                tam:=a[i];
                a[i]:=a[j];
                a[j]:=tam;
        end;
        dem:=1;
        for i:=1 to n do
                if a[i]=a[i+1] then inc(dem)
                else
                begin
                   if dem>demx then
                     begin
                       demx:=dem;
                       m:=a[i];
                     end;
                   dem:=1;
                end;
        writeln('so xuat hien nhieu nhat la:',m);
        write('so lan xuat hien la:',demx);
        readln
end.
