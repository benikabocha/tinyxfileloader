#include <gtest/gtest.h>

#include "../tinyxfileloader.h"

TEST(XFileLoadTest, Basic)
{
    std::string dataPath = SAMPLE_DATA_PATH;

    tinyxfile::XFile xfile;
    tinyxfile::XFileLoader loader;

    // Invalid file path
    EXPECT_FALSE(loader.Load((dataPath + "/invalid.x").c_str(), &xfile));

    // cube.x
    EXPECT_TRUE(loader.Load((dataPath + "/cube.x").c_str(), &xfile));

    // frame count
    EXPECT_EQ(1, xfile.m_frames.size());

    if (xfile.m_frames.size() == 1)
    {
        const auto& frame = xfile.m_frames[0];
        EXPECT_STREQ("", frame->m_name.c_str());

        EXPECT_FLOAT_EQ(1, frame->m_transform.m[0]);
        EXPECT_FLOAT_EQ(0, frame->m_transform.m[1]);
        EXPECT_FLOAT_EQ(0, frame->m_transform.m[2]);
        EXPECT_FLOAT_EQ(0, frame->m_transform.m[3]);

        EXPECT_FLOAT_EQ(0, frame->m_transform.m[4]);
        EXPECT_FLOAT_EQ(1, frame->m_transform.m[5]);
        EXPECT_FLOAT_EQ(0, frame->m_transform.m[6]);
        EXPECT_FLOAT_EQ(0, frame->m_transform.m[7]);

        EXPECT_FLOAT_EQ(0, frame->m_transform.m[8]);
        EXPECT_FLOAT_EQ(0, frame->m_transform.m[9]);
        EXPECT_FLOAT_EQ(1, frame->m_transform.m[10]);
        EXPECT_FLOAT_EQ(0, frame->m_transform.m[11]);

        EXPECT_FLOAT_EQ(0, frame->m_transform.m[12]);
        EXPECT_FLOAT_EQ(0, frame->m_transform.m[13]);
        EXPECT_FLOAT_EQ(0, frame->m_transform.m[14]);
        EXPECT_FLOAT_EQ(1, frame->m_transform.m[15]);

        EXPECT_EQ(nullptr, frame->m_parent);
        EXPECT_EQ(0, frame->m_childFrames.size());

        const auto& mesh = frame->m_mesh;
        EXPECT_EQ(22, mesh.m_positions.size());
        EXPECT_EQ(12, mesh.m_positionFaces.size());

        EXPECT_EQ(22, mesh.m_normals.size());
        EXPECT_EQ(12, mesh.m_normalFaces.size());

        EXPECT_EQ(22, mesh.m_textureCoords.size());

        EXPECT_EQ(2, mesh.m_materials.size());
        EXPECT_STREQ("tex.png", mesh.m_materials[0].m_texture.c_str());

        EXPECT_EQ(12, mesh.m_faceMaterials.size());

    }
}

TEST(XFileLoadTest, Frame)
{
    std::string dataPath = SAMPLE_DATA_PATH;

    tinyxfile::XFile xfile;
    tinyxfile::XFileLoader loader;

    // cube.x
    EXPECT_TRUE(loader.Load((dataPath + "/cube_frame.x").c_str(), &xfile));

    // frame count
    EXPECT_EQ(3, xfile.m_frames.size());

    if (xfile.m_frames.size() == 3)
    {
        const auto& frame = xfile.m_frames[0];
        EXPECT_STREQ("Root", frame->m_name.c_str());

        EXPECT_FLOAT_EQ(1, frame->m_transform.m[0]);
        EXPECT_FLOAT_EQ(0, frame->m_transform.m[1]);
        EXPECT_FLOAT_EQ(0, frame->m_transform.m[2]);
        EXPECT_FLOAT_EQ(0, frame->m_transform.m[3]);

        EXPECT_FLOAT_EQ(0, frame->m_transform.m[4]);
        EXPECT_FLOAT_EQ(1, frame->m_transform.m[5]);
        EXPECT_FLOAT_EQ(0, frame->m_transform.m[6]);
        EXPECT_FLOAT_EQ(0, frame->m_transform.m[7]);

        EXPECT_FLOAT_EQ(0, frame->m_transform.m[8]);
        EXPECT_FLOAT_EQ(0, frame->m_transform.m[9]);
        EXPECT_FLOAT_EQ(1, frame->m_transform.m[10]);
        EXPECT_FLOAT_EQ(0, frame->m_transform.m[11]);

        EXPECT_FLOAT_EQ(0, frame->m_transform.m[12]);
        EXPECT_FLOAT_EQ(0, frame->m_transform.m[13]);
        EXPECT_FLOAT_EQ(0, frame->m_transform.m[14]);
        EXPECT_FLOAT_EQ(1, frame->m_transform.m[15]);

        EXPECT_EQ(nullptr, frame->m_parent);
        EXPECT_EQ(1, frame->m_childFrames.size());
        EXPECT_EQ(xfile.m_frames[1].get(), frame->m_childFrames[0]);

        const auto& mesh = frame->m_mesh;
        EXPECT_EQ(22, mesh.m_positions.size());
        EXPECT_EQ(12, mesh.m_positionFaces.size());

        EXPECT_EQ(22, mesh.m_normals.size());
        EXPECT_EQ(12, mesh.m_normalFaces.size());

        EXPECT_EQ(22, mesh.m_textureCoords.size());

        EXPECT_EQ(2, mesh.m_materials.size());
        EXPECT_STREQ("", mesh.m_materials[0].m_texture.c_str());

        EXPECT_EQ(12, mesh.m_faceMaterials.size());
    }

    if (xfile.m_frames.size() == 3)
    {
        const auto& frame = xfile.m_frames[1];
        EXPECT_STREQ("C01", frame->m_name.c_str());

        EXPECT_FLOAT_EQ(1, frame->m_transform.m[0]);
        EXPECT_FLOAT_EQ(0, frame->m_transform.m[1]);
        EXPECT_FLOAT_EQ(0, frame->m_transform.m[2]);
        EXPECT_FLOAT_EQ(0, frame->m_transform.m[3]);

        EXPECT_FLOAT_EQ(0, frame->m_transform.m[4]);
        EXPECT_FLOAT_EQ(1, frame->m_transform.m[5]);
        EXPECT_FLOAT_EQ(0, frame->m_transform.m[6]);
        EXPECT_FLOAT_EQ(0, frame->m_transform.m[7]);

        EXPECT_FLOAT_EQ(0, frame->m_transform.m[8]);
        EXPECT_FLOAT_EQ(0, frame->m_transform.m[9]);
        EXPECT_FLOAT_EQ(1, frame->m_transform.m[10]);
        EXPECT_FLOAT_EQ(0, frame->m_transform.m[11]);

        EXPECT_FLOAT_EQ(0, frame->m_transform.m[12]);
        EXPECT_FLOAT_EQ(-1.5f, frame->m_transform.m[13]);
        EXPECT_FLOAT_EQ(0, frame->m_transform.m[14]);
        EXPECT_FLOAT_EQ(1, frame->m_transform.m[15]);

        EXPECT_EQ(xfile.m_frames[0].get(), frame->m_parent);
        EXPECT_EQ(1, frame->m_childFrames.size());
        EXPECT_EQ(xfile.m_frames[2].get(), frame->m_childFrames[0]);

        const auto& mesh = frame->m_mesh;
        EXPECT_EQ(0, mesh.m_positions.size());
        EXPECT_EQ(0, mesh.m_positionFaces.size());

        EXPECT_EQ(0, mesh.m_normals.size());
        EXPECT_EQ(0, mesh.m_normalFaces.size());

        EXPECT_EQ(0, mesh.m_textureCoords.size());

        EXPECT_EQ(0, mesh.m_materials.size());

        EXPECT_EQ(0, mesh.m_faceMaterials.size());
    }

    if (xfile.m_frames.size() == 3)
    {
        const auto& frame = xfile.m_frames[2];
        EXPECT_STREQ("C02", frame->m_name.c_str());

        EXPECT_FLOAT_EQ(1, frame->m_transform.m[0]);
        EXPECT_FLOAT_EQ(0, frame->m_transform.m[1]);
        EXPECT_FLOAT_EQ(0, frame->m_transform.m[2]);
        EXPECT_FLOAT_EQ(0, frame->m_transform.m[3]);

        EXPECT_FLOAT_EQ(0, frame->m_transform.m[4]);
        EXPECT_FLOAT_EQ(1, frame->m_transform.m[5]);
        EXPECT_FLOAT_EQ(0, frame->m_transform.m[6]);
        EXPECT_FLOAT_EQ(0, frame->m_transform.m[7]);

        EXPECT_FLOAT_EQ(0, frame->m_transform.m[8]);
        EXPECT_FLOAT_EQ(0, frame->m_transform.m[9]);
        EXPECT_FLOAT_EQ(1, frame->m_transform.m[10]);
        EXPECT_FLOAT_EQ(0, frame->m_transform.m[11]);

        EXPECT_FLOAT_EQ(1, frame->m_transform.m[12]);
        EXPECT_FLOAT_EQ(0, frame->m_transform.m[13]);
        EXPECT_FLOAT_EQ(1, frame->m_transform.m[14]);
        EXPECT_FLOAT_EQ(1, frame->m_transform.m[15]);

        EXPECT_EQ(xfile.m_frames[1].get(), frame->m_parent);
        EXPECT_EQ(0, frame->m_childFrames.size());

        const auto& mesh = frame->m_mesh;
        EXPECT_EQ(22, mesh.m_positions.size());
        EXPECT_EQ(12, mesh.m_positionFaces.size());

        EXPECT_EQ(22, mesh.m_normals.size());
        EXPECT_EQ(12, mesh.m_normalFaces.size());

        EXPECT_EQ(22, mesh.m_textureCoords.size());

        EXPECT_EQ(2, mesh.m_materials.size());
        EXPECT_STREQ("tex.png", mesh.m_materials[0].m_texture.c_str());

        EXPECT_EQ(12, mesh.m_faceMaterials.size());
    }
}
