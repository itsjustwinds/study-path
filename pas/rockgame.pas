type
        int=int64;
var
        a:array[1..100] of longint;
        t,s:array[1..100] of longint;
        dd:array[1..100] of boolean;
        i,j,n:longint;
        res:int64;
procedure result(t:int);
begin
        if t+a[1]*a[n]>res then res:=t+a[1]*a[n];
end;
procedure try(i:longint;tong:int);
var     j,tmpt,tmps,tmp:longint;
begin
        for j:=2 to n-1 do
        if dd[j] then
        begin
                if i<>n-2 then
                begin
                        tmp:=a[t[j]]*a[s[j]];
                        //tmpt:=t[j];tmps:=s[j];
                        s[t[j]]:=s[j];
                        t[s[j]]:=t[j];
                        dd[j]:=false;
                        try(i+1,tong+tmp);
                        dd[j]:=true;
                        t[s[j]]:=j;s[t[j]]:=j;
                end
                else result(tong);
        end;
end;
procedure nhap;
begin
        readln(n);
        for i:=1 to n do
        begin
                read(a[i]);
                t[i]:=i-1;
                s[i]:=i+1;
        end;
        res:=0;
        fillchar(dd,sizeof(dd),true);
        try(1,0);
        writeln(res);
end;
begin
        {assign(input,'rockgame.inp');
        assign(output,'rockgame.out');
        reset(input);
        rewrite(output);}
        nhap;
        {close(input);
        close(output); }
end.