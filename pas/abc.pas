var
        s,kq:string;
        a:array[1..3] of string;
        i,j,n,min:longint;
        kt:boolean;
procedure try(i:longint);
var     j,k,dem:longint;
        s1,skt:STRING;
        check:boolean;
begin
        for j:=1 to 3 do
        if a[j]<>s[i-1] then
        begin
                s1:='';
                check:=true;
                k:=i-1;
                while ((k-1)>=(i-k+1)) do
                begin
                        skt:=copy(s,k-(i-k+1),i-k+1);
                        if ((s[k]+s1+a[j])<>skt) then
                        begin
                                s1:=s[k]+s1;
                                dec(k);
                        end
                        else
                        begin
                                check:=false;
                                break;
                        end;
                end;
                if check then
                begin
                        s:=s+a[j];
                        if i=n then
                        begin
                                for k:=1 to n do
                                        if s[k]='C' then inc(dem);
                                if dem<min then
                                begin
                                        kq:=s;
                                        min:=dem;
                                end;
                        end
                        else try(i+1);
                        delete(s,i,1);
                end;
        end;
end;
procedure nhap;
begin
        readln(n);
        a[1]:='A';a[2]:='B';a[3]:='C';
        s:='';
        kq:='';
        min:=maxlongint;
        for i:=1 to 3 do
        begin
                s:=a[i];
                try(2);
        end;
        writeln(kq);
end;
begin
        assign(input,'abc.inp');
        assign(output,'abc.out');
        reset(input);
        rewrite(output);
        nhap;
        close(input);
        close(output);
end.
