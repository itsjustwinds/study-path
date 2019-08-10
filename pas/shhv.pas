var
        d,i,j,t,dem,k,tg,l:longint;
        a,gt,res,vt:array[0..12] of longint;
        dd:array[1..12] of boolean;
        kt:boolean;
procedure sang;
var     i:longint;
begin
        gt[0]:=1;
        for i:=1 to d do
                gt[i]:=gt[i-1]*i;
end;
procedure try(i:longint);
var     j:longint;
begin
        if kt then exit;
        for j:=1 to d do
        if dd[j] then
        begin
                if kt then exit;
                dd[j]:=false;
                res[i]:=j;
                if i=d then
                begin
                        inc(dem);
                        if dem=k then
                        begin
                                kt:=true;
                                exit;
                        end;
                end
                else try(i+1);
                dd[j]:=true;
                if kt then exit;
        end;
end;
procedure nhap;
var     x:longint;
begin
        while not seekeoln do
        begin
                inc(d);
                read(x);
                a[d]:=x;
        end;
        readln(k);
        sang;
        t:=1;
        for i:=1 to d-1 do
        begin
                dem:=0;
                for j:=i+1 to d do
                        if a[i]>a[j] then inc(dem);
                inc(t,gt[d-i]*dem);
        end;
        writeln(t);
        {dem:=0;
        kt:=false;
        fillchar(dd,d,true);
        try(1);
        for i:=1 to d do
                write(res[i],' ');}
        tg:=1;
        for i:=1 to d do vt[i]:=i;
        for i:=1 to d do
        Begin
                for j:=1 to d do
                if tg+j*gt[d-i]>k then
                begin
                        l:=j;
                        break;
                end;
                tg:=tg+(l-1)*gt[d-i];
                a[i]:=vt[l];
                for j:=l to d do vt[j]:=vt[j+1];
        End;
        for i:=1 to d do write(a[i],' ');

end;
begin
        assign(input,'shhv.inp');
        assign(output,'shhv.out');
        reset(input);
        rewrite(output);
        nhap;
        close(input);
        close(output);
end.