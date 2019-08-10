type
        th=set of 1..30;
var
        a,b,d:array[1..30] of longint;
        sum:array[1..20,1..30] of th;
        i,j,n,m,t,k:longint;
        kt:boolean;
        kq:array[1..30] of th;
function ktra(i:longint;t:th):boolean;
var     j:longint;
begin
        for j:=1 to d[i] do
                if t=sum[j,i] then exit(false);
        exit(true);
end;
procedure find(vt,i,k,tong:longint;t:th);
var     j:longint;
begin
        for j:=k to m do
                if (not (j in t)) and (tong+b[j]<=a[vt]) then
                begin
                        if (tong+b[j]=a[vt])  then
                        begin
                                if (ktra(vt,t+[j])) then
                                begin
                                        inc(d[vt]);
                                        sum[d[vt],vt]:=t+[j];
                                end;
                        end
                        else
                        if j<>m then
                        find(vt,i+1,j+1,tong+b[j],t+[j]);
                end;
end;
procedure check(i:longint;t:th);
var     j,k:longint;
begin
        if kt then exit;
        for j:=1 to d[i] do
        begin
                if kt then exit;
                if t*sum[j,i]=[] then
                begin
                        kq[i]:=sum[j,i];
                        if i=n then
                        begin
                                kt:=true;
                                exit;
                        end
                        else check(i+1,t+sum[j,i]);
                end;
        end;
end;
procedure nhap;
var     h:longint;
begin
        readln(t);
        for k:=1 to t do
        begin
                readln(n,m);
                for i:=1 to n do
                        read(a[i]);
                for j:=1 to m do
                        read(b[j]);
                for i:=1 to n do
                begin
                        d[i]:=0;
                        find(i,1,1,0,[]);
                end;
                kt:=false;
                kq[1]:=[];
                if (n=1) and (d[1]>0) then
                begin
                        kq[1]:=sum[1,1];
                        kt:=true;
                end
                else
                begin
                for i:=1 to d[1] do
                begin
                        kq[1]:=sum[i,1];
                        check(2,sum[i,1]);
                        if kt then break;
                end;
                end;
                if kt then
                        begin
                                for j:=1 to m do
                                begin
                                        kt:=false;
                                        for h:=1 to n do
                                                if j in kq[h] then
                                                begin
                                                        write(h,' ');
                                                        kt:=true;
                                                end;
                                                if kt=false then write(0,' ');
                                end;
                                writeln;
                        end
                else writeln(-1);
        end;
end;
begin
        assign(input,'bank.inp');
        assign(output,'bank.out');
        reset(input);
        rewrite(output);
        nhap;
        close(input);
        close(output);
end.
