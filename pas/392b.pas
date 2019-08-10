type
        str=string;
var
        s:string;
        check:boolean;
        i,j,n:longint;
        a:array[1..4] of char;
        res:array[1..4] of longint;
function kt(i:longint;sk:str):boolean;
begin
        if (i>=4) then
                exit((sk[i]<>sk[i-1]) and (sk[i]<>sk[i-2]) and (sk[i]<>sk[i-3]) and (sk[i-1]<>sk[i-2]) and (sk[i-1]<>sk[i-3]) and (sk[i-2]<>sk[i-3]));
        if (i=3) then
                exit((sk[i]<>sk[i-1]) and (sk[i]<>sk[i-2]) and (sk[i-1]<>sk[i-2]));
        if (i=2) then
                exit(sk[i]<>sk[i-1]);
        exit(true);
end;
procedure result;
begin
        for i:=1 to 4 do
                write(res[i],' ');
end;
procedure try(i:longint;sk:str);
var j:longint;
begin
        if check then exit;
        if (s[i]<>'!') and (kt(i,sk+s[i])) then
        begin
                if i=length(s) then
                begin
                        result;
                        check:=true;
                end
                else
                try(i+1,sk+s[i]);
                if check then exit;
        end
        else if (s[i]='!') then
        begin
                for j:=1 to 4 do
                if kt(i,sk+a[j]) then
                begin
                        inc(res[j]);
                        if (i=length(s)) then
                        begin
                                result;
                                check:=true;
                        end
                        else try(i+1,sk+a[j]);
                        dec(res[j]);
                        if check then exit;
                end;
        end;
end;
procedure nhap;
begin
        readln(s);
        a[1]:='R';
        a[2]:='B';
        a[3]:='Y';
        a[4]:='G';
        check:=false;
        try(1,'');
end;
begin
        assign(input,'392b.inp');
        assign(output,'392b.out');
        reset(input);
        rewrite(output);
        nhap;
        //READLN;
        close(input);
        close(output);
end.