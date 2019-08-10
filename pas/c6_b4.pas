var
        a:array [1..100,1..100] of integer;
        n,i,j,t,p,q,tc,tp:longint;
        kt:boolean;
begin   kt:=true;
        n:=4;
        t:=0;
        tc:=0;
        tp:=0;
        for i:=1 to n do
                for j:=1 to n do
                begin
                        write('nhap A[',i,',',j,']');
                        readln(a[i,j]);
                end;
        for i:=1 to n do
                begin
                t:=0;
                for j:=1 to n do
                        t:=t+a[i,j];
                writeln('tong cac phan tu trong dong ',i,' la:',t);
                end;
        for i:=1 to n do
        begin
                for j:=i to n do
                        if i=j then t:=t+a[i,j];
        end;
                write('tong cac phan tu trong duong cheo chinh la:',t);
                writeln;
        for i:=1 to n do
        begin
                for j:=n downto 1 do
                        if i+j=5 then t:=t+a[i,j];
        end;
                writeln('tong cac phan tu trong duong cheo phu la :',t);
        for i:=1 to n div 2 do
        if a[i,i]<>a[n-i+1,n-i+1] then
        begin
        kt:=false;
        break;
        end;
        if kt=true then write('mang doi xung qua duong cheo')
        else write('mang khong doi xung qua duong cheo');
        readln
end.
