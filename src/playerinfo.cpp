#include "headers.h"

Name_and_Score player;

void Name_and_Score ::save_previous_highest_score_file()
{
    ScoreFile = fopen("Score.txt", "r");
    for (int i = 0; i < 4; i++)
    {
        fscanf(ScoreFile, "%d", &player.save_score[i]);
        // cout << player.save_score[i] << endl;
    }
    fclose(ScoreFile);
}

void Name_and_Score ::save_present_highest_score(string name, int score)
{
    if (score > player.save_score[0])
    {
        player.save_score[0] = score;
        if (name == "" or name == " ")
            player.save_name[0] = "Anonymous";
        else
            player.save_name[0] = name;

        for (int i = 0; i < 3; i++)
        {
            for (int j = i + 1; j < 4; j++)
            {
                if (player.save_score[i] > player.save_score[j])
                {
                    swap(player.save_score[i], player.save_score[j]);
                    swap(player.save_name[i], player.save_name[j]);
                }
            }
        }
        ScoreFile = fopen("Score.txt", "w");
        for (int i = 0; i < 4; i++)
            fprintf(ScoreFile, "%d\n", player.save_score[i]);
        fclose(ScoreFile);
        player.save_present_name(player.input_name);
    }
}

void Name_and_Score ::output_highest_score()
{
    ScoreFile = fopen("Score.txt", "r");
    int SCORE_SHOW[5];
    // string NAME_SHOW[5];
    SDL_Color textColor = {255, 255, 255, 255};
    std::stringstream ScoreText;
    for (int i = 0; i < 4; i++)
    {
        fscanf(ScoreFile, "%d", &SCORE_SHOW[i]);
    }
    for (int i = 3; i >= 0; i--)
    {
        cout << SCORE_SHOW[i] << endl;
        ScoreText.str("");
        ScoreText << SCORE_SHOW[i];
        gHighestScoreTexture.loadFromRenderedText(ScoreText.str().c_str(), textColor);
        gHighestScoreTexture.render(965, 330 + (3 - i) * 100, 0, 0, SDL_FLIP_NONE);
    }
    fclose(ScoreFile);
}

void Name_and_Score ::save_previous_name_file()
{
    NameFile = fopen("Name.txt", "r");
    for (int i = 0; i < 4; i++)
    {
        char c;
        player.save_name[i] = "";
        while ((c = fgetc(NameFile)) != '\n')
        {
            player.save_name[i] += c;
        }
    }
    fclose(NameFile);
}

void Name_and_Score ::save_present_name(string name)
{
    NameFile = fopen("Name.txt", "w");
    for (int i = 0; i < 4; i++)
        fprintf(NameFile, "%s\n", player.save_name[i].c_str());
    fclose(NameFile);
}

void Name_and_Score ::output_name()
{
    NameFile = fopen("Name.txt", "r");
    string NAME_SHOW[5];
    SDL_Color textColor = {255, 255, 255, 255};
    std::stringstream NameText;
    for (int i = 0; i < 4; i++)
    {
        char c;
        NAME_SHOW[i] = "";
        while ((c = fgetc(NameFile)) != '\n')
        {
            NAME_SHOW[i] += c;
        }
        // cout << NAME_SHOW[i] << endl;
    }
    for (int i = 3; i >= 0; i--)
    {
        cout << NAME_SHOW[i] << endl;
        NameText.str("");
        NameText << NAME_SHOW[i];
        gGreatestNameTexture.loadFromRenderedText(NameText.str().c_str(), textColor);
        gGreatestNameTexture.render(400, 330 + (3 - i) * 100, 0, 0, SDL_FLIP_NONE);
    }
    fclose(NameFile);
}

void Name_and_Score ::close_file()
{
    fclose(ScoreFile);
    fclose(NameFile);
}